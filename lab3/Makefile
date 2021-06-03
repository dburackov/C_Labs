all: test

main:
	gcc -std=c89 -o src/main main.c
	./src/main

test:
	gcc -std=c89 -o src/test -Dmain=defmain main.c test.c
	./src/test < tests/in1.txt > src/ans1.txt
	./src/test < tests/in2.txt > src/ans2.txt
	./src/test < tests/in3.txt > src/ans3.txt
	./src/test < tests/in4.txt > src/ans4.txt
	diff tests/out1.txt src/ans1.txt
	diff tests/out2.txt src/ans2.txt
	diff tests/out3.txt src/ans3.txt
	diff tests/out4.txt src/ans4.txt
