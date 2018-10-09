#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <string.h>
using namespace cv;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

    CommandLineParser parser(argc,argv,"{@input | lena.jpg | input image}");
    Mat image = imread(parser.get<String>("@input"));
//    Mat image = imread(argv[1]);
    if (image.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << "<Input image>" << endl;
        return -1;
    }

    Mat new_image = Mat::zeros(image.size(),image.type());

    double alpha = 1.0;

    int beta = 0;

    cout << "Basic Linear Transforms " << endl;
    cout << "------------------------" << endl;
    cout << "*Enter the alpha value [1.0-3.0]: ";
    cin >> alpha;
    cout << "*Enter the beta value[0-100]: ";
    cin >> beta;

    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            for (int c = 0; c < image.channels(); c++)
            {
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(alpha*image.at<Vec3b>(y,x)[c] + beta);
            }
        }
    }
    double gamma_ = 1.4;
    imshow("Original Image",image);
    imshow("New Image",new_image);


    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for( int i = 0; i < 256; ++i)
        p[i] = saturate_cast<uchar>(pow(i / 255.0, gamma_) * 255.0);
    Mat res = image.clone();
    LUT(new_image, lookUpTable, res);

    imshow("gamma",res);
    waitKey(0);
    return 0;
}