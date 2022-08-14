#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        ans[0] = {1};

        for (int i = 1; i < numRows; ++i) {
            ans[i].resize(i + 1);
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) ans[i][j] = 1;
                else ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int numRows;
        cin >> numRows;

        vector<vector<int>> ans = Solution::generate(numRows);
        for (vector<int> &x: ans) {
            for (int &y: x) cout << y << " ";
            cout << endl;
        }
    }
}
