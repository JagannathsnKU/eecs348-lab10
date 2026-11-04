CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: lab10

lab10: main.o Matrix.o
	$(CXX) $(CXXFLAGS) -o lab10 main.o Matrix.o

main.o: main.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cpp

clean:
	rm -f *.o lab10
