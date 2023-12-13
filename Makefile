CXX = g++
CXXFLAGS = -Wall -I./include
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = test
TARGET = $(BUILD_DIR)/main_runner
TEST_TARGET = $(BUILD_DIR)/test_runner

# source files
SRCS = $(wildcard $(SRC_DIR)/*/*.cpp) $(SRC_DIR)/main.cpp
TEST_SRCS = $(wildcard $(TEST_DIR)/*/*.cpp)
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
$(shell mkdir -p $(BUILD_DIR)/feedforward)
$(shell mkdir -p $(BUILD_DIR)/feedforward)

# Clean rule
clean:
	rm -rf $(BUILD_DIR)/*.o

# Full clean rule
fclean:
	rm -rf $(BUILD_DIR)

re: clean all

.PHONY: all test clean fclean re
