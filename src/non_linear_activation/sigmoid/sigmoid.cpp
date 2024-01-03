
#include "non_linear_activation/sigmoid/sigmoid.hpp"

double sigmoid(const double x)
{
    return 1.0 / (1.0 + exp(-x));
}