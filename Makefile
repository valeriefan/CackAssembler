CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = assembler
SRC = src/Assembler.cpp src/Parser.cpp src/SymbolTable.cpp src/Code.cpp
HEADERS = src/Parser.h src/SymbolTable.h src/Code.h
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean