#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

const char* windowName = "Pyramids Demo";


int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

    cout << "\n Zoom In-Out demo \n"
            <<"----------------\n"
            <<endl;

    const char* filename = argc>=2?argv[1]:"lena.jpg";

    Mat src = cv::imread(filename);

    if (src.empty())
    {
        printf("Error open image.\n");
        return -1;
    }
    for (;;)
    {
        cv::imshow(windowName,src);
        char c = (char)waitKey(0);

        if (c == 27)
        {
            break;
        } else if(c == 'i')
        {
            pyrUp(src,src,Size(src.cols*2,src.rows*2));
            printf("**Zoom In:Image x 2\n");
        }
        else if(c == 'o')
        {
            pyrDown(src,src,Size(src.cols/2,src.rows/2));
            printf("**Zoom Out:Image / 2\n");
        }
    }
    return 0;
}