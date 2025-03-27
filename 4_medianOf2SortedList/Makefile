# Makefile for Median of Two Sorted Arrays

CXX = g++
CXXFLAGS = -g -Wall -Wextra
TARGET = median
SRC = Median_Of_Two_SortedList.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
