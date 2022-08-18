#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> ans;
    vector<bool> coloumn;

    bool check(int row, int col, vector<string> &currentBoard, int n) {
        int i = row - 1;
        int left = col - 1;
        int right = col + 1;

        while (i >= 0 && (left >= 0 || right < n)) {
            if (left >= 0 && currentBoard[i][left] == 'Q') return false;
            if (right < n && currentBoard[i][right] == 'Q') return false;
            --i;
            --left;
            ++right;
        }

        i = row + 1;
        left = col - 1;
        right = col + 1;

        while (i < n && (left >= 0 || right < n)) {
            if (left >= 0 && currentBoard[i][left] == 'Q') return false;
            if (right < n && currentBoard[i][right] == 'Q') return false;
            ++i;
            --left;
            ++right;
        }

        return true;
    }

    void isPossible(int row, vector<string> &currentBoard, int n) {
        if (row >= n) {
            ans.push_back(currentBoard);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (!coloumn[col] && check(row, col, currentBoard, n)) {
                currentBoard[row][col] = 'Q';
                coloumn[col] = true;
                isPossible(row + 1, currentBoard, n);
                coloumn[col] = false;
                currentBoard[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> currentBoard;
        coloumn = vector<bool>(n);

        for (int i = 0; i < n; ++i) {
            string row("");
            for (int j = 0; j < n; ++j) {
                row += '.';
            }
            currentBoard.push_back(row);
        }

        isPossible(0, currentBoard, n);

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        Solution solution;
        vector<vector<string>> ans = solution.solveNQueens(n);
        for (vector<string> &x: ans) {
            for (string &y: x) cout << y << endl;
            cout << endl;
        }
    }

    return 0;
}
