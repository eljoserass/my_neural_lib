#ifndef LINEAR
#define LINEAR
#include <Eigen/Dense>

class Linear {
public:
    Linear(const int input_dim, const int output_dim, const int n_rows = 1);
    ~Linear();

    int get_input_dim() const;
    int get_output_dim() const;
    void compute_logits(Eigen::MatrixXf &input);

    Eigen::MatrixXf logits; // publicly available to be read
    

private:
    const int _input_dim;
    const int _output_dim;
    const int _n_rows;

    Eigen::MatrixXf _w;
    //  = Eigen::MatrixXf::Random(_input_dim, _output_dim); 
    // input_dim = aka number of weights, output_dim = aka n of perceptrons
    Eigen::MatrixXf _b;
    // = Eigen::MatrixXf::Ones(_output_dim, _n_rows); // 1 = batch
     // _n_rows , _output_dim  
};


#endif