all: main test

main:
	g++ -o main tourist.cpp main.cpp

test:
	g++ -ftest-coverage -fprofile-arcs -O0 -o test tourist.cpp test.cpp 
	./test
	gcov -abcfu tourist.cpp
	gcov -abcfu main.cpp
