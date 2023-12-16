#include "layers/linear/linear.hpp"

Linear::Linear(const int input_dim, const int output_dim, const int n_rows) : 
    _input_dim(input_dim), _output_dim(output_dim), _n_rows(n_rows) {
    _w = Eigen::MatrixXf::Random(_input_dim, _output_dim);
    _b = Eigen::MatrixXf::Ones(_n_rows, _output_dim);
    logits(_n_rows, _output_dim);
}