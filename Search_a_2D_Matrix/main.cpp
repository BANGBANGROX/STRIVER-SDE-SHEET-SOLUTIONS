#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (matrix[mid / n][mid % n] == target) return true;
            else if (matrix[mid / n][mid % n] > target) r = mid - 1;
            else l = mid + 1;
        }

        return false;
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
        int target;
        cin >> target;

        Solution solution;
        if (solution.searchMatrix(matrix, target)) cout << "true\n";
        else cout << "false\n";
    }

}
