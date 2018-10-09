#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char ** argv)
{
    cout<< "Hello World!" << endl;

    if(argc != 2)
    {
        cout << "Your input argument" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1],1);

    if(!image.data)
    {
        cout << "no data!" << endl;
        return -1;
    }

    namedWindow("display",WINDOW_AUTOSIZE);
    imshow("display",image);

    waitKey(0);

    return 0;
}