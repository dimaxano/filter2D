#include <iostream>

#include "Filter2D.h"

Filter2D::Filter2D(cv::InputArray kernel){
       kernel_ = kernel.getMat();

       assert(kernel_.rows == kernel_.cols);

       kernel_size_ = kernel_.rows;
}

void Filter2D::apply(cv::InputArray image, cv::OutputArray out){
    assert(image.channels() == 1);
    assert(image.type() == 0);

    const int kernel_h_2 = kernel_size_ / 2;
    const int kernel_w_2 = kernel_size_ / 2;
    const float kernel_sum = cv::sum(kernel_).val[0];

    cv::Mat image_mat = image.getMat();
    
    out.createSameSize(image, CV_8UC1);
    cv::Mat out_mat = out.getMat();

    for(size_t y = 0; y < image_mat.rows; y++)
    for(size_t x = 0; x < image_mat.cols; x++){
        float value = 0;

        for(int8_t ky = -kernel_h_2; ky != kernel_size_-1; ky++){
            for(int8_t kx = -kernel_w_2; kx != kernel_size_-1; kx++){
                int pixel = 0;
                const int pixel_y = y - ky;
                const int pixel_x = x - kx;

                if(pixel_x >= 0 && pixel_x < image_mat.cols && pixel_y >= 0 && pixel_y < image_mat.rows){
                    pixel = image_mat.at<uchar>(pixel_y, pixel_x);
                }

                const int8_t weight = kernel_.at<uchar>(ky + kernel_h_2, kx + kernel_w_2);

                value += pixel*weight;
            }
    }
    
    out_mat.at<uchar>(y, x) = value / kernel_sum;

    }
}