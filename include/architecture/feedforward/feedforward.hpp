// include/feedforward/feedforward.hpp

#ifndef FEEDFORWARD
#define FEEDFORWARD

#include <vector>

class Feedforward {
public:

    Feedforward(int inputSize, int hiddenSize, int outputSize);


    ~Feedforward();

    int getInputSize() const;
    int getHiddenSize() const;
    int getOutputSize() const;

    std::vector<double> forward(const std::vector<double>& input);


    void backpropagate(const std::vector<double>& target);

private:
    int inputSize;
    int hiddenSize;
    int outputSize;

};

#endif  // FEEDFORWARD_HPP
