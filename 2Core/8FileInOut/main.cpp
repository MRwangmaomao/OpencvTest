#include <opencv2/core.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

static void help(char** av)
{
    cout << endl
         << av[0] << " shows the usage of the OpenCV serialization functionality."         << endl
         << "usage: "                                                                      << endl
         <<  av[0] << " outputfile.yml.gz"                                                 << endl
         << "The output file may be either XML (xml) or YAML (yml/yaml). You can even compress it by "
         << "specifying this in its extension like xml.gz yaml.gz etc... "                  << endl
         << "With FileStorage you can serialize objects in OpenCV by using the << and >> operators" << endl
         << "For example: - create a class and have it serialized"                         << endl
         << "             - use it to read and write matrices."                            << endl;
}

class MyData
{
public:
    MyData():A(0),X(0),id()
    {}
    explicit  MyData(int):A(97),X(CV_PI),id("mydata1234")
    {}
    void write(FileStorage& fs)const
    {
        fs << "{" << "A" << A << "X" << X << "id" << id << "}";
    }

    void read(const FileNode& node)
    {
        A = (int)node["A"];
        X = (double)node["X"];
        id = (string)node["id"];
    }

public:
    int A;
    double X;
    string id;
};

static void write(FileStorage& fs, const std::string&, const MyData& x)
{
    x.write(fs);
}//写入fs

static void read(const FileNode& node, MyData& x, const MyData& default_value = MyData())
{
    if (node.empty())
        x = default_value;
    else
        x.read(node);
}//读取文件写入x

static ostream& operator<<(ostream& out, const MyData& m)
{
    out << "{ id = " << m.id << ",";
    out << "X = " << m.X << ",";
    out << "A = " << m.A << "}";
    return out;
}//

int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

    if(argc != 2)
    {
        help(argv);
        return 1;
    }

    string filename = argv[1];
    {
        Mat R = Mat_<uchar>::eye(3,3),
        T = Mat_<double>::zeros(3,1);
        MyData m(1);

        FileStorage fs(filename,FileStorage::WRITE);

        fs << "iterationNr" << 100;
        fs << "strings" << "[";
        fs << "image1.jpg" << "Awesomeness" << "lena.jpg";
        fs << "]";

        fs << "Mapping";
        fs << "{" << "One" << 1;
        fs <<   "Two" << 2 << "}";

        fs << "R" << R;
        fs << "T" << T;

        fs.release();
        cout << "Write Done." << endl;
    }

    {
        cout << endl << "Reading:" << endl;
        FileStorage fs;
        fs.open(filename,FileStorage::READ);

        int itNr;
        itNr = (int)fs["iterationNr"];
        cout << itNr;
        if(!fs.isOpened())
        {
            cerr << "Failed to open" << filename << endl;
            help(argv);
            return 1;
        }

        FileNode n = fs["strings"];
        if(n.type()!=FileNode::SEQ)
        {
            cerr << "string is not a sequence! FAIL" << endl;
            return -1;
        }

        FileNodeIterator it = n.begin(),it_end = n.end();
        for(;it != it_end; ++it)
        {
            cout << (string)*it << endl;
        }

        n = fs["Mapping"];
        cout << "Two" << (int)(n["Two"]) << ";";
        cout << "One " << (int)(n["one"]) << endl << endl;

        MyData m;
        Mat R,T;

        fs["R"] >> R;
        fs["T"] >> T;
        fs["MyData"] >> m;

        cout << endl << "R = " << T << endl << endl;
        cout << "MyData = " << endl << m << endl << endl;

        cout << "Attempt to read NonExistiong (should initialize the data structure with its default. )";
        fs["NonExisting"] >> m;
        cout << endl << "NonExisting = " << endl << m << endl;
    }

    cout << endl << "Tip: Open up " << filename << "with a text editor to see the serialized data."<< endl;


    return 0;
}



























