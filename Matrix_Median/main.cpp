#include<bits/stdc++.h>
using namespace std;

class Solution {
    int upperBound(vector<int> &nums, int key) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (nums[mid] <= key) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }

    int countElementsLesserOrEqual(vector<vector<int>> &matrix, int key) {
        int m = matrix.size();
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            ans += upperBound(matrix[i], key);
        }

        return ans;
    }

public:
    int findMedian(vector<vector<int>> &matrix) {
        int l = 1;
        int r = 1e9;
        int m = matrix.size();
        int n = matrix[0].size();

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (countElementsLesserOrEqual(matrix, mid) <= (m * n) / 2) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        Solution solution;
        cout << solution.findMedian(matrix) << endl;
    }

    return 0;
}
