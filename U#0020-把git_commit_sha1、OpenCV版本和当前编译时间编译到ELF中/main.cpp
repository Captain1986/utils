#include "opencv2/opencv.hpp"

// 参考资料：https://www.learnopencv.com/how-to-find-opencv-version-python-cpp/
//           https://www.learnopencv.com/get-opencv-build-information-getbuildinformation/
// 编译方法：g++ getOpenCVInfo.cpp `pkg-config --libs --cflags opencv`
//
//

#define  VERSION_STRING    "ELF v1.0.0, " __DATE__ ", " __TIME__

int main(int argc, char** argv)
{
    // 打印ELF版本和当前编译时间
    std::cout << "Welcome to use " << VERSION_STRING << std::endl;

    // 打印git commit sha1信息
    printf("git_commit_sha1:\t%s\n", GIT_COMMIT_SHA1);

    // 打印OpenCV版本信息（从头文件中拿）
    std::cout << "OpenCV version : " << CV_VERSION << std::endl;
    std::cout << "Major version : " << CV_MAJOR_VERSION << std::endl;
    std::cout << "Minor version : " << CV_MINOR_VERSION << std::endl;
    std::cout << "Subminor version : " << CV_SUBMINOR_VERSION << std::endl;

    // 打印OpenCV编译信息（从库中拿）
    std::cout << cv::getBuildInformation() << std::endl;

    if (CV_MAJOR_VERSION < 3) {
        // Old OpenCV 2 code goes here. 
    } else {
        // New OpenCV 3 code goes here. 
    }

    return 0;
}
