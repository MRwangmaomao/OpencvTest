#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

    double  alpha = 0.5;
    double beta;
    double input;

    Mat src1,src2,dst;

    cout << " Simple Linear Blender " << endl;
    cout << " ---------------------- " << endl;
    cout << " Enter alpha [0.0-1.0]:";
    cin >> input;

    if (input >= 0 && input <= 1 )
    {
        alpha = input;
    }
    alpha = 0.2;
    src1 = cv::imread(argv[1]);
    src2 = cv::imread(argv[2]);

    if (src1.empty())
    {
        cout << " Error loading src1 " << endl;
    }
    if (src2.empty())
    {
        cout << " Error loading src2 " << endl;
    }

    beta = (1.0 - alpha);
    addWeighted(src1, alpha, src2, beta, 0.0, dst);

    imshow("Linear Blend",dst);
    waitKey(0);
    return 0;
}