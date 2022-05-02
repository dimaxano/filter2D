
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "filter2D/Filter2D.h"

int main (int argc, char *argv[]) {
    if(argc != 2){
        std::cerr << "Expecting one argument\n";
        return 1;
    }

    std::string input_filepath = argv[1];

    cv::Mat image = cv::imread(input_filepath, 0);

    cv::Mat kernel = cv::Mat(3, 3, 0, cv::Scalar(1));
    Filter2D filter = Filter2D(kernel);

    cv::Mat out;
    filter.apply(image, out);

    cv::imshow("In", image);
    cv::imshow("Out", out);
    
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;

} 