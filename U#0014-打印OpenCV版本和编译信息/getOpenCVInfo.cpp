#include "opencv2/opencv.hpp"

// 参考资料：https://www.learnopencv.com/how-to-find-opencv-version-python-cpp/
//           https://www.learnopencv.com/get-opencv-build-information-getbuildinformation/
// 编译方法：g++ getOpenCVInfo.cpp `pkg-config --libs --cflags opencv`
//
int main( int argc, char** argv )
{
    // 打印版本信息（从头文件中拿）
    std::cout << "OpenCV version : " << CV_VERSION << std::endl;
    std::cout << "Major version : " << CV_MAJOR_VERSION << std::endl;
    std::cout << "Minor version : " << CV_MINOR_VERSION << std::endl;
    std::cout << "Subminor version : " << CV_SUBMINOR_VERSION << std::endl;

    // 打印编译信息（从库中拿）
    std::cout << cv::getBuildInformation() << std::endl;

    if ( CV_MAJOR_VERSION < 3) {
        // Old OpenCV 2 code goes here. 
    } else {
        // New OpenCV 3 code goes here. 
    }

    return 0;
}
