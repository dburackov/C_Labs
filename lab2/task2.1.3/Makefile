all: test

main:
	gcc -std=c89 -o src/main src/main.c
	./src/main

test:
	gcc -std=c89 -o src/test -Dmain=defmain src/main.c src/test.c
	./src/test
