#include <iostream>
#include <cassert>
#include "MultiSet.h"

void testNumberOfLeaves() {
	MultiSet<int> ms;
	ms.insert(5);
	ms.insert(5);
	ms.insert(10);
	ms.insert(0);
	ms.insert(100);
	ms.insert(4);
	assert(ms.numberOfLeaves() == 2);
	ms.insert(-1);
	assert(ms.numberOfLeaves() == 3);
	ms.insert(6);
	assert(ms.numberOfLeaves() == 4);
	ms.erase(6);
	assert(ms.numberOfLeaves() == 3);
}

int main() {
	testNumberOfLeaves();
	return 0;
}