all: main

main:
	if not exist bin md bin
	gcc -std=c89 -o bin/main main.c
	./bin/main

test:
	if not exist bin md bin
	gcc -std=c89 -o bin/test -Dmain=defmain main.c test.c
	./bin/test < tests/in1.txt > bin/ans1.txt
	./bin/test < tests/in2.txt > bin/ans2.txt
	./bin/test < tests/in3.txt > bin/ans3.txt
	./bin/test < tests/in4.txt > bin/ans4.txt
	diff tests/out1.txt bin/ans1.txt
	diff tests/out2.txt bin/ans2.txt
	diff tests/out3.txt bin/ans3.txt
	diff tests/out4.txt bin/ans4.txt

clear:
	rd /s /q bin 
