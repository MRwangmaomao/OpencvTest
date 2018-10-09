#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char ** argv) {

    std::cout << "Hello, World!" << std::endl;

    Mat A,C;  //只是创建了矩阵的头部

    A = imread(argv[1], IMREAD_COLOR); //自动分配矩阵大小

    Mat B(A); //复制的是指针头部

    C = A; //配置运算符
/******************
 上面的都是指向相同对象的矩阵，只要一个修改，就会引起其他的变化
 * 底层相同，但是标题部分不同
 * ********************/


//    Mat D(A,Rect(10,10,100,100));
//    Mat E = A(Range::all(),Range(1,3));
/*****
 * 矩阵有一个矩阵计数器，当计数器为零时，矩阵被释放
 * ****/

    //使用ｃｖ::Mat::clone 和　cv::Mat::copyTo　方法复制
    Mat F = A.clone();
    Mat G;
    A.copyTo(G);

    //cv::Mat::Mat 构造函数
    Mat M(2,2,CV_8UC3,Scalar(0,0,255));
    cout << "M = " << endl << " " << M << endl << endl;

    int sz[3] = {2,2,2};
    Mat L(3, sz, CV_8UC(1),Scalar::all(0));
    //cv::Mat::creat()
    M.create(4,4,CV_8UC(3));
    cout << "M = " << endl << " " << M << endl << endl;

    //cv::Mat::eye
    Mat E = Mat::eye(4,4,CV_64F);
    cout << "E " << "= " << E << endl << endl;

    //cv::Mat::ones
    Mat O = Mat::ones(4,4,CV_32F);
    cout << "O " << "= " << " " << O << endl << endl;

    //cv::Mat::zeros
    Mat Z = Mat::zeros(3,3,CV_8UC1);
    cout << "Z = " << Z << endl << endl;

    //对于小型矩阵，使用逗号分割的初始化程序或者初始化程序列表
    Mat Q = (Mat_<double> (3,3) << 1,0,0,0,1,0,0,0,1);
    cout << "Q = " << Q << endl << endl;

    Q = (Mat_<double>({0,0,-1,0,0,0,1,1,1})).reshape(3);
    cout << "Q = " << Q << endl << endl;

    //为现有的Mat对象创建一个新的矩阵
    Mat RowClone = M.row(1).clone();
    cout << "RowClone = " << endl << " " << RowClone << endl << endl;

    //随机矩阵
    Mat R = Mat(3,2,CV_8UC3);
    randu(R,Scalar::all(0),Scalar::all(255));
    cout << " R = " << endl << R << endl << endl;

    //输出格式控制
    cout << "R(default) = " << endl << R << endl << endl; //默认

    cout << "R(python) = " << endl << format(R,Formatter::FMT_PYTHON) << endl << endl; //python 形式

    cout << "R(CSV) = " << endl << format(R,Formatter::FMT_CSV) << endl << endl; //CSV 形式

    cout << "R(Numpy) = " << endl << format(R,Formatter::FMT_NUMPY) << endl << endl; //Numpy 形式

    cout << "R(Matlab) = " << endl << format(R,Formatter::FMT_MATLAB) << endl << endl; //Matlab 形式*/


    //2Ｄ点输出
    Point2f P(5,1);
    cout << "Point2f(2D) = " << endl << P << endl << endl;

    //3Ｄ点输出
    Point3f P3f(2,6,7);
    cout << "Point3f(3D) = " << endl << P3f << endl << endl;

    //vector via Mat
    vector <float> v;
    v.push_back((float)CV_PI);
    v.push_back(2);
    v.push_back(3.01f);
    cout << "vector of floats via Mat = " << Mat(v) << endl << endl;

    //点向量
    vector<Point2f> vPoints(20);
    for (size_t i = 0; i < vPoints.size(); ++i)
        vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
    cout << "A vector of 2D Points = " << vPoints << endl << endl;

    return 0;

}