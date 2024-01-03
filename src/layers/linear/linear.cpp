#include "layers/linear/linear.hpp"

Linear::Linear(const int input_dim, const int output_dim, const int n_rows) : 
    _input_dim(input_dim), _output_dim(output_dim), _n_rows(n_rows),  logits(_n_rows, _output_dim){
    _w = Eigen::MatrixXf::Random(_input_dim, _output_dim);
    _b = Eigen::MatrixXf::Ones(1, _output_dim);
    // logi = Eigen
}

Linear::~Linear() {}

int Linear::get_input_dim()  { return _input_dim; }

int Linear::get_output_dim() { return _output_dim; }

Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Linear::get_w(void) {
    return _w;
}

Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Linear::get_b(void) {
    return _b;
}

void Linear::compute_logits(Eigen::MatrixXf input) {
    logits = input * _w;
    logits.rowwise() += _b;
}