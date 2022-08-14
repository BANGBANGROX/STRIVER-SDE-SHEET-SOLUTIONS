#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paths are (m + n - 2 m - 1)

    int uniquePaths(int m, int n) {
        long ans = 1;

        for (int i = 1; i < n; ++i) {
            ans *= ((long)m + i - 1);
            ans /= i;
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m >> n;

        Solution solution;
        cout << solution.uniquePaths(m, n) << endl;
    }

    return 0;
}
