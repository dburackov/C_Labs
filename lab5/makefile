all: test clear

main:
	g++ -o main main.cpp
	./main

test:
	g++ -o test main.cpp test.cpp
	./test

clear:
	del test.exe
	del main.exe