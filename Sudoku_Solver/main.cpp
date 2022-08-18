#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> centers = {{1, 1}, {4, 1}, {7, 1}, {1, 4}, {4, 4}, {7, 4}, {1, 7},
                                   {4, 7}, {7, 7}};


    bool check(int row, int col, vector<vector<char>> &board) {
        vector<bool> visited(10);

        // Check col
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == '.') continue;
            if (visited[board[i][col] - '0']) return false;
            visited[board[i][col] - '0'] = true;
        }

        // Check row
        visited = vector<bool>(10);

        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == '.') continue;
            if (visited[board[row][i] - '0']) return false;
            visited[board[row][i] - '0'] = true;
        }

        // Find the 3x3 sub-grid
        vector<int> center;
        int minDistance = INT_MAX;

        for (int i = 0; i < 9; ++i) {
            int dis = abs(row - centers[i][0]) + abs(col - centers[i][1]);
            if (dis < minDistance) {
                minDistance = dis;
                center = centers[i];
            }
        }

        int top = center[0] - 1;
        int bottom = center[0] + 1;
        int left = center[1] - 1;
        int right = center[1] + 1;
        visited = vector<bool>(10);

        for (int i = top; i <= bottom; ++i) {
            for (int j = left; j <= right; ++j) {
                if (board[i][j] == '.') continue;
                if (visited[board[i][j] - '0']) return false;
                visited[board[i][j] - '0'] = true;
            }
        }

        return true;
    }


    bool isPossible(int row, int col, vector<vector<char>> &board) {
        if (row >= 9) return true;

        if (col >= 9) return isPossible(row + 1, 0, board);

        if (board[row][col] != '.') return isPossible(row, col + 1, board);

        for (int dig = 1; dig < 10; ++dig) {
            board[row][col] = (dig + '0');
            if (check(row, col, board)) {
                if (isPossible(row, col + 1, board)) return true;
            }
        }

        board[row][col] = '.';

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        isPossible(0, 0, board);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<vector<char>> board(9, vector<char>(9));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cin >> board[i][j];
            }
        }

        Solution solution;
        solution.solveSudoku(board);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
