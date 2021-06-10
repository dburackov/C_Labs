all: main test

main:
	g++ -o main tourist.cpp main.cpp

test:
	g++ -ftest-coverage -fprofile-arcs -O0 -o test -Dmain=_main tourist.cpp main.cpp test.cpp 
	./test
	gcov -abcfu main.cpp
	gcov -abcfu tourist.cpp