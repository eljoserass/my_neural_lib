#ifndef LINEAR
#define LINEAR
#include <Eigen/Dense>

// add to namspece "layers"
class Linear {
public:
    Linear(const int input_dim, const int output_dim, const int n_rows = 1);
    // n_rows may be removed as is only used in logits
    ~Linear(void);

    int get_input_dim(void);
    int get_output_dim(void);
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> get_w(void);
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> get_b(void);
    void compute_logits(Eigen::MatrixXf input); // change to be reference and not copy

    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> logits;

private:
    const int _input_dim;
    const int _output_dim;
    const int _n_rows;

    Eigen::Matrix<double, 1, Eigen::Dynamic> _b;
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> _w;
    // Eigen::MatrixXf _w;
    // Eigen::MatrixXf _b;  
};


#endif