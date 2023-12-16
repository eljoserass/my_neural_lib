#include <iostream> 
#include "architecture/feedforward/feedforward.hpp"
#include <Eigen/Dense>

int main(void) {
    Feedforward neuralNetwork(2, 3, 1);
    std::cout << "hello" << std::endl;
    const int inpu_d = 2;
    Eigen::Matrix<float , inpu_d, 3> input {
        {1,2,1},
        {0,3,1}
    };
    Eigen::Matrix<float , 3, 2> w {
        {1, 1},
        {0.5, 0.5},
        {2,2}
    };

    Eigen::Matrix<float, 2,2> b {{1, 1},{1,1}
    };
    std::cout << input * w + b<< std::endl;
    return 0;
}