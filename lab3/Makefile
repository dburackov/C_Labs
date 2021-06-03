all: test

main:
	gcc -std=c89 -o main main.c
	./main

test:
	gcc -std=c89 -o test -Dmain=defmain main.c test.c
	./test < tests/in1.txt > ans1.txt
	./test < tests/in2.txt > ans2.txt
	./test < tests/in3.txt > ans3.txt
	./test < tests/in4.txt > ans4.txt
	diff tests/out1.txt ans1.txt
	diff tests/out2.txt ans2.txt
	diff tests/out3.txt ans3.txt
	diff tests/out4.txt ans4.txt
