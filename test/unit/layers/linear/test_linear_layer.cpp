#include <gtest/gtest.h>
#include "layers/linear/linear.hpp"
#include "iostream"

TEST(LinearLayerTest, InitDimension) {
    Linear linear_layer(3, 2);
    
    EXPECT_EQ(linear_layer.get_input_dim(), 3);
    EXPECT_EQ(linear_layer.get_output_dim(), 2);
    // TODO replace to check actual matrices

}

TEST(LinearLayerTest, LogitsDimensions) {
    int input_dim = 3;

    int output_dim = 2;

    int n_rows = 2;
    Linear linear_layer(input_dim, output_dim, n_rows);
    
    // TODO check actual dims
    // just print for now because i dont rememebr the function

    Eigen::Matrix<float , 2, 3> input {
        {0,0,0},
        {1,1,1}
    };


    linear_layer.compute_logits(input);

    std::cout << linear_layer.logits << std::endl;
}