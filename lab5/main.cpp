#include <stack>

std::stack<int> merge(std::stack<int> a, std::stack<int> b) {
    std::stack<int> temp;
    std::stack<int> result;
    while (!a.empty() || !b.empty()) {
        if (a.empty()) {
            temp.push(b.top());
            b.pop();
        } else if (b.empty()) {
            temp.push(a.top());
            a.pop();
        } 
        if (!a.empty() && !b.empty()) {
            if (a.top() > b.top()) {
                temp.push(a.top());
                a.pop();
            } else {
                temp.push(b.top());
                b.pop();
            }
        }
    }
    while (!temp.empty()) {
        if (result.empty()) {
            result.push(temp.top());
        } else if (temp.top() != result.top()) {
            result.push(temp.top());
        }
        temp.pop();
    }
    return result;
}