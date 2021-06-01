all: test clear

main:
	gcc -std=c89 -o main src/main.c
	./main

test:
	gcc -std=c89 -o test -Dmain=defmain src/main.c src/test.c
	./test

clear:
	del main.exe
	del test.exe