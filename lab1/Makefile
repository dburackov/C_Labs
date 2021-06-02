all: test clear

clear:
	rd /s /q temp

test:
	md temp
	gcc -std=c89 -o temp/test -Dmain=defmain src/main.c src/test.c
	temp/test
