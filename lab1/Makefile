all: clear buildTest runTest

clear:
	rd /s /q temp

buildTest:
	md temp
	gcc -std=c89 -o temp/test -Dmain=defmain src/main.c src/test.c

runTest:
	temp/test