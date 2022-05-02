#include <opencv2/core.hpp>

class Filter2D{
public:
    Filter2D(cv::InputArray kernel);

    void apply(cv::InputArray image, cv::OutputArray out);

private:
    size_t kernel_size_;
    cv::Mat kernel_;
};