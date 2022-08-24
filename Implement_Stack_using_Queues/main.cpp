#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;

public:
    MyStack() {

    }

    void push(int x) {
        q.push(x);

        int n = q.size();

        for (int i = 1; i < n; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;

        int ans = q.front();
        q.pop();

        return ans;
    }

    int top() {
       return q.front();
    }

    bool empty() {
       return q.empty();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
