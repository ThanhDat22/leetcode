# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = add_two_numbers

# Source file
SRCS = Add_2_Numbers.cpp
OBJS = $(SRCS:.cpp=.o)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run with user input
run: $(TARGET)
	@echo "Running with user input..."
	./$(TARGET)

# Run all test cases
test: $(TARGET)
	@echo "Running Test Case 1: 243 + 564"
	./$(TARGET) 1
	@echo "Running Test Case 2: 0 + 0"
	./$(TARGET) 2
	@echo "Running Test Case 3: 9999999 + 9999"
	./$(TARGET) 3
	@echo "Running Test Case 4: 21 + 9"
	./$(TARGET) 4
	@echo "Running Test Case 5: 5 + 7"
	./$(TARGET) 5
	@echo "Running Test Case 6: 9999999 + 9999999"
	./$(TARGET) 6
	@echo "Running Test Case 7: 692 + 418"
	./$(TARGET) 7
	@echo "Running Test Case 8: 210 + 300"
	./$(TARGET) 8
	@echo "Running Test Case 9: 465 + 645"
	./$(TARGET) 9
	@echo "Running Test Case 10: 99 + 1 "
	./$(TARGET) 10

# Run individual test cases
test1: $(TARGET)
	./$(TARGET) 1

test2: $(TARGET)
	./$(TARGET) 2

test3: $(TARGET)
	./$(TARGET) 3

test4: $(TARGET)
	./$(TARGET) 4

test5: $(TARGET)
	./$(TARGET) 5

test6: $(TARGET)
	./$(TARGET) 6

test7: $(TARGET)
	./$(TARGET) 7

test8: $(TARGET)
	./$(TARGET) 8

test9: $(TARGET)
	./$(TARGET) 9

test10: $(TARGET)
	./$(TARGET) 10


# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)
