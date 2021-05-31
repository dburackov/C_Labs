all: test

main:
	if not exist bin md bin
	gcc -std=c89 -o bin/main src/main.c src/str.c
	bin/main

test:
	if not exist bin md bin
	gcc -std=c89 -o bin/test -Dmain=defmain src/str.c src/main.c src/test.c
	bin/test

clear:
	rd /s /q bin
	