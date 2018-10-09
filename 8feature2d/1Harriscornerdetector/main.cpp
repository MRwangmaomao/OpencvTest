#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,src_gray;
int thresh = 200;
int max_thresh = 255;

const char* sourceWindow = "Source image";
const char* cornersWindow = "Corners detected";

void cornerHarris_demo(int,void*);

int main(int argc,char** argv)
{
    CommandLineParser parser(argc,argv,"{input|building.jpg|}");
    src = cv::imread(parser.get<string>("input"));
    if(src.empty())
    {
        cout << "Could not open or  find the image!\n" << endl;
        cout << "Usage:" << argv[0] << "<Input image>" << endl;
        return -1;
    }
    cvtColor(src,src_gray,COLOR_BGR2GRAY);
    cout << "OK\n" << endl;
    namedWindow(sourceWindow);
    createTrackbar("Threshold:",sourceWindow,&thresh,max_thresh,cornerHarris_demo);
    imshow(sourceWindow,src);


    cornerHarris_demo(0,0);
    waitKey();

    return 0;
}

void cornerHarris_demo(int,void*)
{
    int blockSize = 2;
    int apertureSize = 3;
    double k = 0.04;

    Mat dst = Mat::zeros(src.size(),CV_32FC1);
    cornerHarris(src_gray,dst,blockSize,apertureSize,k);

    Mat dst_norm,dst_norm_scaled;
    normalize(dst,dst_norm,0,255,NORM_MINMAX,CV_32FC1,Mat());

    convertScaleAbs(dst_norm,dst_norm_scaled);

    for (int i = 0; i < dst_norm.rows; i++)
    {
        for (int j = 0; j < dst_norm.cols; j++)
        {
            if ((int)dst_norm.at<float>(i,j) > thresh)
            {
                circle(dst_norm_scaled,Point(j,i),5,Scalar(0),2,8,0);
            }
        }
    }
    cout << "OK\n" << endl;
    namedWindow(cornersWindow);
    imshow(cornersWindow,dst_norm_scaled);
}