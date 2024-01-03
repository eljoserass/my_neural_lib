CXX = g++
# CXX =  nvcc
CXXFLAGS = -Wall -I./include
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = test/unit
TARGET = $(BUILD_DIR)/main_runner
TEST_TARGET = $(BUILD_DIR)/test_runner

# source files
SRCS = $(wildcard $(SRC_DIR)/*/*/*.cpp) $(SRC_DIR)/main.cpp
TEST_SRCS = $(wildcard $(TEST_DIR)/*/*/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SRCS))

all: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

# build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# build the test executable
$(TEST_TARGET): $(filter-out $(BUILD_DIR)/main.o, $(OBJS)) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lgtest -lgtest_main -pthread

# build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# create build directories
# TODO see how to fix this
create_dir:
	$(shell mkdir -p $(BUILD_DIR)/architecture/feedforward)
	$(shell mkdir -p $(BUILD_DIR)/layers/linear)
	$(shell mkdir -p $(BUILD_DIR)/loss/cross_entropy)
	$(shell mkdir -p $(BUILD_DIR)/non_linear_activation/sigmoid)

# Clean rule
clean:
	rm -rf $(wildcard $(BUILD_DIR)/*/*.o)

# Full clean rule
fclean:
	rm -rf $(BUILD_DIR)

re: fclean create_dir all

.PHONY: all test clean fclean re create_dir
