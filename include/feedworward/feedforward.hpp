// include/feedforward/feedforward.hpp

#ifndef FEEDFORWARD
#define FEEDFORWARD

#include <vector>

class Feedforward {
public:
    // Constructor
    Feedforward(int inputSize, int hiddenSize, int outputSize);

    // Destructor
    ~Feedforward();

    // Getters for network sizes
    int getInputSize() const;
    int getHiddenSize() const;
    int getOutputSize() const;

    // Forward propagate input through the network and get the output
    std::vector<double> forward(const std::vector<double>& input);

    // Backpropagate the error and update weights
    void backpropagate(const std::vector<double>& target);

private:
    int inputSize;
    int hiddenSize;
    int outputSize;

    // Other necessary private members for your implementation
};

#endif  // FEEDFORWARD_HPP
