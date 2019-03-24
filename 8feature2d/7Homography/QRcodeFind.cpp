//
// Created by wpr on 18-11-22.
// 功能:二维码定位
// 参考网址:https://blog.csdn.net/guanyonglai/article/details/59644437
//

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace cv;
using namespace std;


Point Center_cal(vector<vector<Point> > contours,int i)//找到所提取轮廓的中心点
{
    int centerx=0,centery=0,n=contours[i].size();
    //在提取的小正方形的边界上每隔周长个像素提取一个点的坐标，求所提取四个点的平均坐标（即为小正方形的大致中心）
    centerx = (contours[i][n/4].x + contours[i][n*2/4].x + contours[i][3*n/4].x + contours[i][n-1].x)/4;
    centery = (contours[i][n/4].y + contours[i][n*2/4].y + contours[i][3*n/4].y + contours[i][n-1].y)/4;
    Point point1=Point(centerx,centery);
    return point1;
}


int main()
{
    Mat src; Mat src_gray;
    RNG rng(12345);
    //图像读取和灰度化,滤波,直方图均衡化
    src = imread( "../QR5.png", 1 );
    Mat src_all=src.clone();
    cvtColor( src, src_gray, CV_BGR2GRAY );
//  src_gray = Scalar::all(255) - src_gray;
    blur( src_gray, src_gray, Size(3,3) );
    equalizeHist( src_gray, src_gray );
//    imshow("滤波后",src_gray);

    //二值化
    Scalar color = Scalar(1,1,255 );
    Mat threshold_output;
    threshold( src_gray, threshold_output, 150, 255, THRESH_BINARY );
    //Canny(src_gray,threshold_output,136,196,3);
    imshow("预处理后：",threshold_output);
//    waitKey(0);

    //查找轮廓
    vector<vector<Point> > contours,contours2;
    vector<Vec4i> hierarchy;
    findContours( threshold_output, contours, hierarchy,  CV_RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0) );
    //CHAIN_APPROX_NONE全体,CV_CHAIN_APPROX_SIMPLE,,,RETR_TREE    RETR_EXTERNAL    RETR_LIST   RETR_CCOMP

    //筛选出二维码的四个角
    Mat drawing = Mat::zeros( src.size(), CV_8UC3 );
    Mat drawing2 = Mat::zeros( src.size(), CV_8UC3 );
    int c=0,ic=0,k=0,contours_count=0;
    double area=0;
    //程序的核心筛选
    int parentIdx=-1;
    for( int i = 0; i< contours.size(); i++ )
    {
        if (hierarchy[i][2] != -1 && ic==0)
        {
            parentIdx = i;
            ic++;
        }
        else if (hierarchy[i][2] != -1)
        {
            ic++;
        }
        else if(hierarchy[i][2] == -1)
        {
            ic = 0;
            parentIdx = -1;
        }

        if ( ic >= 2)
        {
            contours2.push_back(contours[parentIdx]);
            drawContours( drawing, contours, parentIdx,  CV_RGB(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)) , 1, 8);
            ic = 0;
            parentIdx = -1;
            area = contourArea(contours[i]);//得出一个二维码定位角的面积，以便计算其边长（area_side）（数据覆盖无所谓，三个定位角中任意一个数据都可以）
            contours_count ++;
        }
        //cout<<"i= "<<i<<" hierarchy[i][2]= "<<hierarchy[i][2]<<" parentIdx= "<<parentIdx<<" ic= "<<ic<<endl;
    }
//    cout << contours_count << endl;  //输出查找到的角的个数
    if( contours_count < 3)  //没有找到二维码,退出查找程序
    {
        std::cout << "没有找到二维码" << std::endl;
        return(0);
    }

    //画出找到的轮廓
    for(int i=0; i<contours2.size(); i++)
        drawContours( drawing2, contours2, i,  CV_RGB(rng.uniform(100,255),rng.uniform(100,255),rng.uniform(100,255)) , -1, 4, hierarchy[k][2], 0, Point() );
//    imshow( "提取后", drawing2 );
//    waitKey(0);


    Point point[3];
    for(int i=0; i<contours2.size(); i++)
    {
        point[i] = Center_cal( contours2, i );
    }
//    std::cout << contours2[1].size();
//    if(contours2[1].size())

    area = contourArea(contours2[1]);//为什么这一句和前面一句计算的面积不一样呢

    int area_side = cvRound (sqrt (area));


    for(int i=0; i<contours2.size(); i++)
    {
        line(drawing2,point[i%contours2.size()],point[(i+1)%contours2.size()],color,area_side/2,8);
    }

    imshow( "提取后", drawing2 );
//    printf("%d\n", contours.size());
    imshow( "Contours", drawing );


    //接下来要框出这整个二维码
    Mat gray_all,threshold_output_all;
    vector<vector<Point> > contours_all;
    vector<Vec4i> hierarchy_all;
    cvtColor( drawing2, gray_all, CV_BGR2GRAY );


    threshold( gray_all, threshold_output_all, 45, 255, THRESH_BINARY );
    findContours( threshold_output_all, contours_all, hierarchy_all,  RETR_EXTERNAL, CHAIN_APPROX_NONE, Point(0, 0) );//RETR_EXTERNAL表示只寻找最外层轮廓


    //求最小包围矩形，斜的也可以哦
    RotatedRect rectPoint = minAreaRect(contours_all[0]);
    vector<cv::Point2f > cv_fourPoint2f(4);
    Point2f fourPoint2f[4];


    //将rectPoint变量中存储的坐标值放到 fourPoint的数组中
    rectPoint.points(fourPoint2f); //得到四个角的数组

    int four_i = 0;
    for(auto i:cv_fourPoint2f)
    {
        i.x = fourPoint2f[four_i].x;
        i.y = fourPoint2f[four_i].y;
        cout << i.x << " " << i.y << endl;
        four_i++;
    }

    //显示框出来的效果
    for (int i = 0; i < 4; i++)
    {
        line(src_all, fourPoint2f[i%4], fourPoint2f[(i + 1)%4]
                , Scalar(20,21,237), 3);
    }
    imshow( "二维码", src_all );
    waitKey(0);

    //计算相机的位姿
    Mat camMatrix = (Mat_<double>(3, 3) << 1.0599465578241038e+03, 0., 9.5488326677588441e+02, 0.,1.0539326808799726e+03, 5.2373858291060583e+02, 0., 0., 1. );
    Mat distCoeff = (Mat_<double>(5, 1) << 5.6268441170930321e-02, -7.4199141308694802e-02, 1.4250797540545752e-03, -1.6951722389720336e-03, 2.4107681263086548e-02 );

    //实际坐标点
    vector<cv::Point3f > m_markerCorners3f;

    float side_length = 0.50f;
    m_markerCorners3f.emplace_back(cv::Point3f(side_length, 0.0f, side_length));
    m_markerCorners3f.emplace_back(cv::Point3f(+0.0f, 0.0f, side_length));
    m_markerCorners3f.emplace_back(cv::Point3f(+0.0f, 0.0f, +0.0f));
    m_markerCorners3f.emplace_back(cv::Point3f(side_length, 0.0f, 0.0f));
    for(auto m_i :m_markerCorners3f)
    cout << m_i << " " << endl;
    Mat r,t;
    cv::solvePnP(m_markerCorners3f, cv_fourPoint2f, camMatrix, distCoeff, r, t, false);
    Mat R_r;
    cv::Rodrigues(r,R_r);
    cout << R_r << endl << t << endl;
    return(0);
}