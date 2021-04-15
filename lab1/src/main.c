#include <stdio.h>

#define MAX_INPUT_VALUE 600000

int input() {
	int result = 0;
	while (result < 1 || result > MAX_INPUT_VALUE) {
		while (!scanf("%d", &result)) {
			while(getchar()!='\n');
		}
	}
	return result;
}

int cube(int value) {
	return value * value * value;
}

int cubeLength(int value) {
	value = cube(value);
	int result = 0;
	while (value) {
		++result;
		value /= 10;
	}
	return result;
}

int solve(int k) {
	int current = 0;
	while (k > cubeLength(current)) {
		k -= cubeLength(current);
		++current;
	}
	k = cubeLength(current) - k;
	current = cube(current);
	while (k--) {
		current /= 10;	 
	}
	return current % 10;
}

int main() {
	int k = input();
	printf("%d", solve(k));
	return 0;
}