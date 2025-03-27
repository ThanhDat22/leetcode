# Makefile for Two_Sum.cpp

CXX = g++
CXXFLAGS = -g -Wall 
TARGET = Two_Sum
SRC = Two_Sum.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
