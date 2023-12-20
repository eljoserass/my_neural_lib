#include "layers/linear/linear.hpp"

Linear::Linear(const int input_dim, const int output_dim, const int n_rows) : 
    _input_dim(input_dim), _output_dim(output_dim), _n_rows(n_rows),  logits(n_rows, output_dim){
    _w = Eigen::MatrixXf::Random(_input_dim, _output_dim);
    _b = Eigen::MatrixXf::Ones(1, _output_dim);
}

Linear::~Linear() {}

int Linear::get_input_dim()  { return _input_dim; }

int Linear::get_output_dim() { return _output_dim; }

void Linear::compute_logits(Eigen::MatrixXf input) {
    logits = input * _w;
    logits.rowwise() += _b;
}