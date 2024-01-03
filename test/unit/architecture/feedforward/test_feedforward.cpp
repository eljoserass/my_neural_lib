#include <gtest/gtest.h>
#include "architecture/feedforward/feedforward.hpp"
#include "iostream"

TEST(FeedforwardTest, BasicFunctionality) {
    Feedforward neuralNetwork(2, 3, 1);

    EXPECT_EQ(neuralNetwork.getInputSize(), 2);
    EXPECT_EQ(neuralNetwork.getHiddenSize(), 3);
    EXPECT_EQ(neuralNetwork.getOutputSize(), 1);

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
