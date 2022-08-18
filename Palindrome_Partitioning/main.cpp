#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> ans;
    vector<vector<bool>> dp;

    void generate(string &s, vector<string> &currentPartition, int index) {
        if (index == (int) s.size()) {
            ans.push_back(currentPartition);
            return;
        }

        string currentString("");

        for (int i = index; i < (int) s.size(); ++i) {
            currentString += s[i];
            if (dp[index][i]) {
                currentPartition.push_back(currentString);
                generate(s, currentPartition, i + 1);
                currentPartition.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp = vector<vector<bool>>(n, vector<bool>(n));
        vector<string> currentPartition;

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (i == j) dp[i][j] = true;
                else if (len == 2) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (dp[i + 1][j - 1] && (s[i] == s[j]));
            }
        }

        generate(s, currentPartition, 0);

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        Solution solution;
        vector<vector<string>> ans = solution.partition(s);
        for (vector<string> &x: ans) {
            for (string &y: x) cout << y << " ";
            cout << endl;
        }
    }

    return 0;
}
