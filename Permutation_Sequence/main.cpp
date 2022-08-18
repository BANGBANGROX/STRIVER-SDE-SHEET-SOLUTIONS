#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1);
        string unused("");
        string ans("");

        factorial[0] = 1;

        for (int i = 1; i <= n; ++i) {
            unused += to_string(i);
            factorial[i] = i * factorial[i - 1];
        }

        --k;

        while (n > 0) {
            int fact = factorial[n] / n;
            int index = k / fact;
            ans += unused[index];
            unused.erase(unused.begin() + index);
            k %= fact;
            --n;
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        Solution solution;
        cout << solution.getPermutation(n, k) << endl;
    }

    return 0;
}
