//
// Created by wpr on 18-11-26.
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

int main() {
    Mat src; Mat src_gray;
    vector<Point2f> image_points_buff;
    Size board_size = Size(4,6);
    Size image_size;

    //图像读取和灰度化,滤波,直方图均衡化
    src = imread( "../boardchess1.png", 1 );
    Mat src_all=src.clone();
    cvtColor( src, src_gray, CV_BGR2GRAY );

    image_size.width = src.cols;
    image_size.height = src.rows;

    if(findChessboardCorners(src,board_size,image_points_buff) == 0)
    {
        cout << "找不到角点信息!!!" << endl;
        return 0;
    }
    else
    {
        find4QuadCornerSubpix(src_gray,image_points_buff,Size(5,5));
        drawChessboardCorners(src_all, board_size, image_points_buff, false);

        imshow("预处理后：",src_all);
        waitKey(0);
    }
    int i = 0;
    for(auto aa:image_points_buff)
    {
        cout << ++i << ": " << aa.x << "    " << aa.y << "      ";
        if((i%4) == 0)
            cout << endl;
    }

    return 0;
}