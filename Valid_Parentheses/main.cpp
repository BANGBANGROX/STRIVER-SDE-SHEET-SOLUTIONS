#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else {
                if (st.empty()) return false;
                char open = '(';
                if (ch == '}') open = '{';
                else if (ch == ']') open = '[';
                if (st.top() != open) return false;
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        Solution solution;
        if (solution.isValid(s)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}
