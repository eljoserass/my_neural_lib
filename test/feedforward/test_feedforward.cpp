// test/feedforward/test_feedforward.cpp

#include <gtest/gtest.h>
#include "feedworward/feedforward.hpp"


// Test the basic functionality of the feedforward neural network
TEST(FeedforwardTest, BasicFunctionality) {
    // Create a feedforward neural network with 2 input neurons, 3 hidden neurons, and 1 output neuron
    Feedforward neuralNetwork(2, 3, 1);

    // Perform some basic tests
    EXPECT_EQ(neuralNetwork.getInputSize(), 2);
    EXPECT_EQ(neuralNetwork.getHiddenSize(), 3);
    EXPECT_EQ(neuralNetwork.getOutputSize(), 1);

    // You can add more tests based on your specific implementation
    // For example, test the forward propagation, backpropagation, etc.
}

// You can add more test cases for different aspects of your feedforward neural network

// Entry point for the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
