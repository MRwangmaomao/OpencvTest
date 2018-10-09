#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

Mat src2;


Mat src1 = cv::imread("lena.jpg");

Mat dst = Mat::zeros( src1.size(), src1.type() );

static void on_trackbar(int,void*)
{
    alpha = (double)alpha_slider/alpha_slider_max;
    beta = 0;
//    for (int y = 0; y < src1.rows; ++y){
//        for (int x = 0; x < src1.cols; ++x){
//            for (int c = 0; c < src1.channels(); c++)
//            {
//                dst.at<Vec3b>(x,y)[c] = saturate_cast<uchar>(src1.at<Vec3b>(x,y)[c]+beta);
//            }
//        }
//    }
//    imshow("Linear Blend",src1);
}

int main(void) {
    std::cout << "Hello, World!" << std::endl;

    alpha_slider = 50;
    namedWindow("Linear Blend",WINDOW_AUTOSIZE);

    char TrackbarName[50];
    sprintf(TrackbarName,"Linear Blend",alpha_slider_max);

    createTrackbar(TrackbarName,"Linear Blend",&alpha_slider,alpha_slider_max,on_trackbar);
    waitKey(0);
    return 0;
}