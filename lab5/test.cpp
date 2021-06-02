#include "main.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <stack>

bool test(std::string file) {
    std::ifstream fin(file);
    bool result = true;
    int n;
    int m;
    std::stack<int> a;
    std::stack<int> b;
    std::stack<int> mrg;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        fin >> temp;
        a.push(temp);
    }
    fin >> m;
    for (int i = 0; i < m; ++i) {
        int temp;
        fin >> temp;
        b.push(temp);
    }
    mrg = merge(a, b);
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        fin >> temp;
        if (mrg.empty()) {
            result = false;
        } else if (mrg.top() != temp) {
            result = false;
        }
        if (!mrg.empty()) {
            mrg.pop();
        }
    }
    return result;
}

int main() {
    assert(test("tests/test1.txt"));
    assert(test("tests/test2.txt"));
    assert(test("tests/test3.txt"));
    assert(test("tests/test4.txt"));
    assert(test("tests/test5.txt"));
    assert(test("tests/test6.txt"));
    assert(test("tests/test7.txt"));
    assert(test("tests/test8.txt"));
    assert(test("tests/test9.txt"));
    std::cout << "All tests passed!\n";
    return 0;
}