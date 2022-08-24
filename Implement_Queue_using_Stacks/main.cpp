#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {

    }

    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
            return;
        }

        s2.push(x);

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) return -1;

        int top = s1.top();
        s1.pop();

        return top;
    }

    int peek() {
       if (s1.empty()) return -1;

       return s1.top();
    }

    bool empty() {
       return s1.empty();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
