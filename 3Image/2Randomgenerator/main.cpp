#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

const int NUMBER = 20;

int x_1 = 100, x_2 = 400, y_1 = 100, y_2 = 400;

static Scalar RandomColor(RNG& rng)
{
    int icolor = (unsigned)rng;
    return Scalar(icolor&255,(icolor>>8)&255,(icolor>>16)&255);
}

int DrawingRandomLines(Mat image,char* windowName, RNG rng)
{
    int lineType = 8;
    Point pt1,pt2;

    for (int i = 0; i < NUMBER; i++)
    {
        pt1.x = rng.uniform(x_1,x_2);
        pt1.y = rng.uniform(y_1,y_2);
        pt2.x = rng.uniform(x_1,x_2);
        pt2.y = rng.uniform(y_1,y_2);

        line(image,pt1,pt2,RandomColor(rng),rng.uniform(1,10),8);
//        imshow(windowName,image);
//        if(waitKey(1) >= 0)
//        {
//            return -1;
//        }
    }
    return 0;
}

int DisplayRandomText(Mat image, char* windowName, RNG rng)
{
    int lineType = 8;

    for (int i = 1; i < NUMBER; i++)
    {
        Point org;
        org.x = rng.uniform(x_1,x_2);
        org.y = rng.uniform(y_1,y_2);
        //windowName：要写的内容　　org：坐标　　rng.uniform:字体类型　rng.uniform(0,100)*0.05+0.1 字体的大小[0.1,5.1]　randomColor 字体颜色　　rng.uniform(1,10)：字体宽度
        putText(image,windowName,org,rng.uniform(0,8),rng.uniform(0,100)*0.05+0.1,RandomColor(rng),rng.uniform(1,10),lineType);
    }
}

int DisplayBigEnd(Mat image, char* windowName, RNG rng)
{
    Size textsize = getTextSize("Opencv test!",FONT_HERSHEY_COMPLEX,3,5,0);
    Point org((image.cols - textsize.width)/2,(image.rows - textsize.height)/2);
    Mat image2;
    int lineType = 8;

    for(int i = 0; i < 40; i += 2)
    {
        image2 = image - Scalar::all(i);
        putText(image2,"opencv forever!",org,FONT_HERSHEY_COMPLEX,2,Scalar(i,i,255),5,lineType);


    }
    imshow("window2",image2);
    waitKey(0);
    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    RNG rng(0xFFFFFFFF);
    int windowHeight = 500;
    int windowWidth = 500;
    Mat image = Mat::zeros(windowHeight,windowWidth,CV_8UC3);
    Mat image2;
    char window_name[] = "test";

    int c = 0;

    c = DrawingRandomLines(image, window_name, rng);
    if( c != 0 ) return 0;
    c = DrawingRandomLines(image, window_name, rng);
    if( c != 0 ) return 0;
    c = DrawingRandomLines( image, window_name, rng );
    if( c != 0 ) return 0;
    c = DrawingRandomLines( image, window_name, rng );
    if( c != 0 ) return 0;
    c = DrawingRandomLines( image, window_name, rng );
    if( c != 0 ) return 0;
    c = DrawingRandomLines( image, window_name, rng );
    if( c != 0 ) return 0;
    c = DrawingRandomLines( image, window_name, rng );
    if( c != 0 ) return 0;
    c = DrawingRandomLines( image, window_name, rng );

    DisplayRandomText(image, window_name, rng);

    DisplayBigEnd(image,window_name, rng);

    imshow(window_name,image);

    waitKey(0);
    return 0;
}