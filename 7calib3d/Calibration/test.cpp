//
// Created by wpr on 18-11-29.
//

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <fstream>


using namespace cv;
using namespace std;



int main()
{

    vector<Point2f> image_points_buff_;
    Size board_size_;
    Mat rotation_;
    Mat translation_;
    float side_length_;
    Mat camMatrix_;
    Mat distCoeff_;
    vector<cv::Point3f > m_markerCorners3f_;
    Size image_size;  /* 图像的尺寸 */
    side_length_ = 0.01;
    board_size_ = Size(11,8);

    camMatrix_ = (Mat_<double>(3, 3) << 549.3614688099561, 0, 467.7511711982686,0, 549.182463904573, 264.1110229919456,0, 0, 1);
    distCoeff_ = (Mat_<double>(5, 1) << 0.02028639459828988, -0.0316434448076687, -0.004822193466304281, -0.0002702970842550804, -0.006882014944184185);
    for(auto m = 1; m <= 11; m++)
        for(int n = 1; n <= 8; n++)
        {
            m_markerCorners3f_.push_back(cv::Point3f(side_length_*m, side_length_*n, 0.0));
        }
    for(auto i:m_markerCorners3f_)
        cout << i.x << "  " << i.y << "  " << i.z << "  " << endl;

    Mat src=imread("../CameraCalibration/0011_color.jpg");
    image_size.width = src.cols;
    image_size.height =src.rows;
    Mat src_gray;
    Mat src_all=src.clone();
    cvtColor( src, src_gray, CV_BGR2GRAY );
    if(findChessboardCorners(src,board_size_,image_points_buff_) == 0)
    {
        std::cout << "找不到角点信息!!!" << endl;
    }
    else
    {
        find4QuadCornerSubpix(src_gray,image_points_buff_,Size(5,5));
        drawChessboardCorners(src_all, board_size_, image_points_buff_, false);
        // int i = 0;
        // for(auto aa:image_points_buff_)
        // {
        //     cout << ++i << ": " << aa.x << "    " << aa.y << "      ";
        //     if((i%4) == 0)
        //         cout << endl;
        // }
        Mat r;


//        calibrateCamera(object_points,image_points_seq,image_size,cameraMatrix,distCoeffs,rvecsMat,tvecsMat,0);
        calibrateCamera(m_markerCorners3f_,image_points_buff_,image_size,camMatrix_,distCoeff_,r,translation_,0);
//        cv::solvePnPRansac( m_markerCorners3f_, image_points_buff_, camMatrix_, distCoeff_, r, translation_, false);
//        cv::solvePnP(m_markerCorners3f_, image_points_buff_, camMatrix_, distCoeff_, r, translation_, false);

        cv::Rodrigues(r,rotation_);
        std::cout << rotation_ << std::endl << translation_ << std::endl;

        /* 计算新的投影点和旧的投影点之间的误差*/
        vector<Point2f> image_points2; //保存重新计算得到的投影点
        double err = 0.0; //每幅图像的平均误差
        projectPoints(m_markerCorners3f_,r,translation_,camMatrix_,distCoeff_,image_points2);

        Mat tempImagePointMat = Mat(1,image_points_buff_.size(),CV_32FC2);
        Mat image_points2Mat = Mat(1,image_points2.size(), CV_32FC2);
        for (int j = 0 ; j < image_points_buff_.size(); j++)
        {
            image_points2Mat.at<Vec2f>(0,j) = Vec2f(image_points2[j].x, image_points2[j].y);
            tempImagePointMat.at<Vec2f>(0,j) = Vec2f(image_points_buff_[j].x, image_points_buff_[j].y);
        }
        err = norm(image_points2Mat, tempImagePointMat, NORM_L2);
        std::cout << "图像的平均误差：" << err<<"像素"<<endl;
        /* 计算新的投影点和旧的投影点之间的误差*/
        cout << endl << endl;
        cv::imshow("display", src_all);
        cv::waitKey(0);
    }


    std::cout<<"保存结束"<<endl;
    return 0;
}