#include <iostream> 
#include "architecture/feedforward/feedforward.hpp"
#include <Eigen/Dense>

int main(void) {
    Feedforward neuralNetwork(2, 3, 1);
    std::cout << "hello" << std::endl;
    const int rows = 2;
    const int attr = 3;
    const int neurons = 2;
    Eigen::Matrix<float , rows, attr> input {
        {0,0,0},
        {1,1,1}
    };
    Eigen::Matrix<float , attr, neurons> w {
        {1, 1},
        {0.5, 0.5},
        {2,2}
    };

    // Eigen::Matrix<float, 2,2> b {{1, 1},{1,1}
    // };
    Eigen::Matrix<float, rows, neurons> result;
    Eigen::Matrix<float, 1, neurons> b;
    b << 1.f, 2.f;
    std::cout << b.transpose() << std::endl;
    // auto resultt = input * w;
    // result += b;
    result = input * w;
    std::cout << "before b \n" << result << std::endl;
    // result = input * w +  b.transpose().replicate(input.rows(), 1);
    result.rowwise() += b;
    std::cout << result << std::endl;
    return 0;
}