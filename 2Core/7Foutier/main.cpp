#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

    const char* filename = argc >= 2? argv[1]:"lena.jpg";

    Mat I = cv::imread(filename, IMREAD_GRAYSCALE);
    if(I.empty()){
        cout << "Error opening image" << endl;
        return -1;
    }

    Mat padded; //为了让ＤＦＴ的是速度最快，需要调整图像大小为２，３，５的倍数
    int m = getOptimalDFTSize(I.rows);
    int n = getOptimalDFTSize(I.cols);

    copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0)); //扩大图像

    //存储一个实部矩阵和一个虚部矩阵
    Mat planes[] = {Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F)};  //扩大的内容填充０元素
    Mat complexI; //
    merge(planes,2,complexI); //合并两个矩阵到complexI

    dft(complexI,complexI); //结果放入原矩阵

    split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
    magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
    Mat magI = planes[0];

    magI += Scalar::all(1);                    // switch to logarithmic scale
    log(magI, magI);

    magI += Scalar::all(1);                    // switch to logarithmic scale
    log(magI, magI);

    //交换象限　重新排列
    // crop the spectrum, if it has an odd number of rows or columns
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
    // rearrange the quadrants of Fourier image  so that the origin is at the image center
    int cx = magI.cols/2;
    int cy = magI.rows/2;
    Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right
    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);


    normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a
    // viewable image form (float between values 0 and 1).


    return 0;
}