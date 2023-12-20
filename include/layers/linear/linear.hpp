#ifndef LINEAR
#define LINEAR
#include <Eigen/Dense>

// add to namspece "layers"
class Linear {
public:
    Linear(const int input_dim, const int output_dim, const int n_rows = 1);
    // n_rows may be removed as is only used in logits
    ~Linear();

    int get_input_dim();
    int get_output_dim();
    void compute_logits(Eigen::MatrixXf input); // change to be reference and not copy

    Eigen::Matrix logits;// can be changed to be dynamic size at compile time
    

private:
    const int _input_dim;
    const int _output_dim;
    const int _n_rows;

    Eigen::MatrixXf _w;
    Eigen::MatrixXf _b;  
};


#endif