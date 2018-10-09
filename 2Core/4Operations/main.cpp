#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc,char **argv) {
    std::string filename = argv[1];
    {
        Mat img = cv::imread(filename);
        CV_UNUSED(img);
    }

    {
        //读取一个jpg图像，默认是３通道，IMREAD_GRAYSCALE会转化为灰度图像
        Mat img = cv::imread(filename, IMREAD_GRAYSCALE);
        CV_UNUSED(img);
    }
    {
        Mat img = cv::imread(filename, IMREAD_GRAYSCALE);
        CV_UNUSED(img);
    }
    {
        Mat img = cv::imread(filename, IMREAD_GRAYSCALE);
        CV_UNUSED(img);
        //imshow("imwrite",img);
        waitKey(0);
    }
    {
        //Mat img(4,4,CV_8U);
        //cv::imwrite(filename,img);


    }
    {
        Mat img(4,4,CV_8U);
        int y = 0, x = 0;
        {
            Scalar intensity = img.at<uchar>(x,y);
            CV_UNUSED(intensity);
        }
        {
            Vec3b intensity = img.at<Vec3b>(x,y);
            uchar blue = intensity.val[0];
            uchar green = intensity.val[1];
            uchar red = intensity.val[2];

            CV_UNUSED(blue);
            CV_UNUSED(green);
            CV_UNUSED(red);
        }
        {
            Vec3f intensity = img.at<Vec3f>(y, x);
            float blue = intensity.val[0];
            float green = intensity.val[1];
            float red = intensity.val[2];

            CV_UNUSED(blue);
            CV_UNUSED(green);
            CV_UNUSED(red);
        }
        {
            img.at<uchar>(y,x) = 128;
        }
        {
            int i = 0;
            vector<Point2f> points;
            Mat pointsMat = Mat(points);

            Point2f point = pointsMat.at<Point2f>(i,0);

            CV_UNUSED(point);
        }
    }

    {
        std::vector<Point3f> points;

        Mat pointsMat = Mat(points).reshape(1);

        CV_UNUSED(pointsMat);
    }
    {
        Mat img = cv::imread(argv[1]);
        Mat img1 = img.clone();

        CV_UNUSED(img1);
    }

    {
        Mat img = cv::imread(argv[1]);
        Mat sobelx;
        Sobel(img,sobelx,CV_32F,1,0);
    }

//    {
//        Mat img;
//        {
//            img = Scalar(0); //设置　图像为空白
//        }
//        {
//            Rect r(10,10,100,100);
//            Mat smallImg = img(r);　　//设置ＲＯＩ
//
//            CV_UNUSED(smallImg);
//        }
//    }

    {
        Mat img = cv::imread(argv[1]);
        IplImage img1 = img;
        CvMat m = img;

        CV_UNUSED(img1);
        CV_UNUSED(m);
    }

    {
        Mat img = cv::imread(argv[1]);
        Mat grey;
        cvtColor(img,grey,COLOR_BGR2GRAY); //转化为灰度图像格式
    }

    {
        Mat dst, src;
        src.convertTo(dst, CV_32F); //转化为ＣＶ32_F格式
    }

    {
        Mat img = cv::imread(argv[1]);
        namedWindow("image",WINDOW_AUTOSIZE);
        imshow("image",img);
        cv::waitKey(0);
    }
    {
        Mat img = cv::imread(argv[1]);
        Mat grey;
        cvtColor(img,grey,COLOR_BGR2GRAY);
        Mat sobelx;
        Sobel(grey,sobelx,CV_32F,1,0);
        namedWindow("image11",WINDOW_AUTOSIZE);
        imshow("image11", sobelx);
        double  minVal, maxVal;
        minMaxLoc(sobelx, &minVal, &maxVal);
        Mat draw;
        sobelx.convertTo(draw, CV_8U, 255.0/(maxVal - minVal));
        namedWindow("image",WINDOW_AUTOSIZE);
        imshow("image", draw);
        cv::waitKey(0);
    }
    std::cout << "Hello, World!" << std::endl;



    return 0;
}

