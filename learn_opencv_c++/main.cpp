#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    cv::Mat img = cv::imread(argv[1], -1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
