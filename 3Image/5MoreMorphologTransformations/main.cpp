#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
Mat src,dst;

int morph_elem = 0;
int morph_size = 0;
int morph_operator = 0;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;

const char* windowName = "Morphology Transformations Demo";

void Morphology_Operations(int,void*);

int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

    CommandLineParser parser(argc,argv,"{input|lena.jpg|}");

    src = imread(parser.get<String>("input"),IMREAD_COLOR);

    if (src.empty())
    {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage:" << argv[0] << "<Input image>" << std::endl;
        return -1;
    }

    namedWindow(windowName,WINDOW_AUTOSIZE);

    createTrackbar( "Operator:\n0:Opening -1:Closing\n2:Gradient -3:Top Hat\n4:Black Hat",windowName,&morph_operator,max_operator,Morphology_Operations);
    createTrackbar( "Element:\n 0: Rect - 1: Cross - 2: Ellipse", windowName,&morph_elem, max_elem,Morphology_Operations );
    createTrackbar( "Kernel size:\n 2n +1", windowName,&morph_size, max_kernel_size,Morphology_Operations);

    Morphology_Operations( 0, 0 );

    waitKey(0);

    return 0;
}



void Morphology_Operations( int, void* )
{
    // Since MORPH_X : 2,3,4,5 and 6
    int operation = morph_operator + 2;
    Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
    morphologyEx( src, dst, operation, element );
    imshow( windowName, dst );
}



