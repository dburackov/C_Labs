all: test

main:
	if not exist temp md temp
	gcc -std=c89 -o temp/main src/main.c
	temp/main

test:
	if not exist temp md temp
	gcc -std=c89 -o temp/test -Dmain=defmain src/main.c src/test.c
	temp/test

clear:
	rd /s /q temp