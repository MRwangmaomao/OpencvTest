#include <iostream>
#include <vector>
#include <opencv/cv.hpp>
#include "opencv2/core.hpp"

#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"

using namespace cv;
using std::cout;
using std::endl;
using std::vector;

int main( int argc, char* argv[] )
{
    //-- 读取图像
    Mat img_1 = imread ( "../904_o.png", CV_LOAD_IMAGE_COLOR );
    Mat img_2 = imread ( "../904.png", CV_LOAD_IMAGE_COLOR );
    Mat image_object = img_1.clone();
    //-- 初始化
    std::vector<KeyPoint> keypoints_1, keypoints_2;
    Mat descriptors_1, descriptors_2;
    Ptr<FeatureDetector> detector = ORB::create();
    Ptr<DescriptorExtractor> descriptor = ORB::create();
    // Ptr<FeatureDetector> detector = FeatureDetector::create(detector_name);
    // Ptr<DescriptorExtractor> descriptor = DescriptorExtractor::create(descriptor_name);
    Ptr<DescriptorMatcher> matcher  = DescriptorMatcher::create ( "BruteForce-Hamming" );

    //-- 第一步:检测 Oriented FAST 角点位置
    detector->detect ( img_1,keypoints_1 );
    detector->detect ( img_2,keypoints_2 );

    //-- 第二步:根据角点位置计算 BRIEF 描述子
    descriptor->compute ( img_1, keypoints_1, descriptors_1 );
    descriptor->compute ( img_2, keypoints_2, descriptors_2 );

    Mat outimg1;
    drawKeypoints( img_1, keypoints_1, outimg1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    imshow("ORB特征点",outimg1);

    //-- 第三步:对两幅图像中的BRIEF描述子进行匹配，使用 Hamming 距离
    vector<DMatch> matches;
    //BFMatcher matcher ( NORM_HAMMING );
    matcher->match ( descriptors_1, descriptors_2, matches );

    //-- 第四步:匹配点对筛选
    double min_dist=10000, max_dist=0;

    //找出所有匹配之间的最小距离和最大距离, 即是最相似的和最不相似的两组点之间的距离
    for ( int i = 0; i < descriptors_1.rows; i++ )
    {
        double dist = matches[i].distance;
        if ( dist < min_dist ) min_dist = dist;
        if ( dist > max_dist ) max_dist = dist;
    }

    // 仅供娱乐的写法
    min_dist = min_element( matches.begin(), matches.end(), [](const DMatch& m1, const DMatch& m2) {return m1.distance<m2.distance;} )->distance;
    max_dist = max_element( matches.begin(), matches.end(), [](const DMatch& m1, const DMatch& m2) {return m1.distance<m2.distance;} )->distance;

    printf ( "-- Max dist : %f \n", max_dist );
    printf ( "-- Min dist : %f \n", min_dist );

    //当描述子之间的距离大于两倍的最小距离时,即认为匹配有误.但有时候最小距离会非常小,设置一个经验值30作为下限.
    std::vector< DMatch > good_matches;
    for ( int i = 0; i < descriptors_1.rows; i++ )
    {
        if ( matches[i].distance <= max ( 2*min_dist, 30.0 ) )
        {
            good_matches.push_back ( matches[i] );
        }
    }

    //-- 第五步:绘制匹配结果
    Mat img_match;
    Mat img_goodmatch;
    drawMatches ( img_1, keypoints_1, img_2, keypoints_2, matches, img_match );
    drawMatches ( img_1, keypoints_1, img_2, keypoints_2, good_matches, img_goodmatch );
    imshow ( "所有匹配点对", img_match );

    waitKey(0);

    vector<Point2f> obj;
    vector<Point2f> scene;

    for(size_t i = 0; i < good_matches.size(); i++)
    {
        obj.push_back(keypoints_1[good_matches[i].queryIdx].pt);
        scene.push_back(keypoints_2[good_matches[i].trainIdx].pt);
    }

    Mat H = findHomography(obj, scene, RANSAC);

    vector<Point2f> obj_corners(4);
    obj_corners[0] = Point2f(0, 0);
    obj_corners[1] = Point2f((float)image_object.cols, 0);
    obj_corners[2] = Point2f((float)image_object.cols, (float)image_object.rows);
    obj_corners[3] = Point2f(0, (float)image_object.rows);

    vector<Point2f> scene_corners(4);

    perspectiveTransform(obj_corners, scene_corners, H);

    line(img_goodmatch, scene_corners[0] + Point2f((float)image_object.cols, 0),
            scene_corners[1] + Point2f((float)image_object.cols, 0), Scalar(0, 255, 0), 4);
    line(img_goodmatch, scene_corners[1] + Point2f((float)image_object.cols, 0),
         scene_corners[2] + Point2f((float)image_object.cols, 0), Scalar(0, 255, 0), 4);
    line(img_goodmatch, scene_corners[2] + Point2f((float)image_object.cols, 0),
         scene_corners[3] + Point2f((float)image_object.cols, 0), Scalar(0, 255, 0), 4);
    line(img_goodmatch, scene_corners[3] + Point2f((float)image_object.cols, 0),
         scene_corners[0] + Point2f((float)image_object.cols, 0), Scalar(0, 255, 0), 4);

    for(auto aa:scene_corners)
        cout << aa.x << "  " << aa.y << endl;

    imshow ( "优化后匹配点对", img_goodmatch );
    waitKey();
    return 0;
}