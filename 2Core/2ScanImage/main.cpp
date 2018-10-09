#include <iostream>
#include <sstream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>

using namespace cv;
using namespace std;


static void help()
{
    cout
        << "\n--------------------------------------------------" << endl
        << "This program show how to scan image objects in opencv (cv::Mat) . As use case"
        << "input. shows C operator[] method, iterators and function for on-the-fly item address calculation." << endl
        << endl;
}

Mat& ScanImageAndReduceC(Mat& I, const uchar* table);
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* table);
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* table);


int main(int argc, char ** argv) {

    std::cout << "Hello, World!" << std::endl;

    help();

    //判断参数是否为３,小于３就认为错误
    if (argc < 3)
    {
        cout << "Not enough parameters" << endl;
        return -1;
    }

    //读取图像
    Mat I,J;
    //判断参数为４的时候检查是否要转化为灰度图像
    if(argc == 4 && !strcmp(argv[3],"G"))
        I = cv::imread(argv[1], IMREAD_GRAYSCALE);
    else
        I = cv::imread(argv[1], cv::IMREAD_COLOR);
    //图像是否为空
    if(I.empty())
    {
        cout << "The image " << argv[1] << " could not be loaded." << endl;
        return -1;
    }

    int divideWith = 0;
    stringstream s;
    s << argv[2]; //输入为string
    s >> divideWith; //输出为数字　　字符串转化为数字的一个方法
    if(!s || !divideWith)
    {
        cout << "Invalid number entered for dividing. " << endl;
        return -1;
    }

    //分区
    uchar table[256];
    for (int i = 0; i < 256; ++i)
    {
        table[i] = (uchar)(divideWith * (i/divideWith));
    }


    const int times = 100;  //循环100次测试
    double t;

    /***************************1******************************/
    t = (double)getTickCount();

    for (int i = 0; i < times; i++)
    {
        cv::Mat clone_i = I.clone();
        J = ScanImageAndReduceC(clone_i,table); //使用Ｃ的方法
    }

    t = 1000*((double)getTickCount() - t)/getTickFrequency();
    t /= times;

    cout << "Time of reducing with the C operator [] averaged for " << times << " runs : " << t << "milliseconds. " << endl;

    imshow("display1",J);
    waitKey(0);

    /****************************2*****************************/
    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
    {
        cv::Mat clone_i = I.clone();
        ScanImageAndReduceRandomAccess(clone_i, table);
    }

    t = 1000 * ((double)getTickCount() - t)/getTickFrequency();
    t /= times;

    cout << "Time of reducing with the on-the-fly address generation - at function (averaged for " << times << " runs):" << t << " milliseconds. " << endl;

    /****************************3*****************************/
    Mat lookUpTable(1,256,CV_8U);

    uchar* p = lookUpTable.ptr();

    for( int i = 0; i < 256; ++i)
        p[i] = table[i];

    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
    {
        LUT(I,lookUpTable,J);
    }

    t = 1000*((double)getTickCount() - t)/getTickFrequency();
    t /= times;

    cout << "time of refuction with the LUT function (average for " << times << " runs): " << t << "milliseconds. " <<endl;

    /*****************4***************************/
    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
    {
        cv::Mat clone_i = I.clone();
        J = ScanImageAndReduceIterator(clone_i, table);
    }

    t = 1000*((double)getTickCount() - t)/getTickFrequency();
    t /= times;

    cout << "Time of reducing with the iterator (averaged for "
         << times << " runs): " << t << " milliseconds."<< endl;



    return 0;
}

Mat& ScanImageAndReduceC(Mat& I, const uchar*const table)
{
    CV_Assert(I.depth() == CV_8U); //CV_8U格式图像

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels; //总列数 = 列数×通道数

    if (I.isContinuous()) //是否连续 连续的话转化为１行的形式
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    uchar* p;
    for (i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i); //行指针
        for (j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]]; //
        }
    }
    return I;
}


Mat& ScanImageAndReduceIterator(Mat& I, const uchar*const table)
{
    CV_Assert(I.depth() == CV_8U);

    const int channels = I.channels();
    switch (channels)
    {
        case 1:
        {
            MatIterator_<uchar> it,end;
            for (it=I.begin<uchar>(),end = I.end<uchar>(); it != end; ++it)
            {
                *it = table[*it];
            }
            break;
        }
        case 3:
        {
            MatIterator_<Vec3b> it,end;
            for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
            {
                (*it)[0] = table[(*it)[0]];
                (*it)[1] = table[(*it)[1]];
                (*it)[2] = table[(*it)[2]];
            }
            break;
        }
    }

    return I;
}


Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar*const table)
{
    CV_Assert(I.depth() == CV_8U);

    const int channels = I.channels();

    switch(channels)
    {
        case 1:
        {
            for (int i = 0; i < I.rows; ++i)
                for (int j = 0; j < I.cols; ++j)
                    I.at<uchar>(i,j) = table[I.at<uchar>(i,j)];
            break;
        }
        case 3:
        {
            Mat_<Vec3b> _I = I;

            for (int i = 0; i < I.rows; ++i)
            {
                for (int j = 0; j < I.cols; ++j)
                {
                    _I(i,j)[0] = table[_I(i,j)[0]];
                    _I(i,j)[1] = table[_I(i,j)[1]];
                    _I(i,j)[2] = table[_I(i,j)[2]];
                }
            }
            I = _I;
            break;
        }
    }

    return I;
}



















