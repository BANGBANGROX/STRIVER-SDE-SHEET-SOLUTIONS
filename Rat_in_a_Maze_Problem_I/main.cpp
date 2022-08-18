//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    vector<string> ans;

    void generate(vector<vector<int>> &maze, int x, int y, string &currentPath) {
        int m = maze.size();
        int n = maze[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n || maze[x][y] == 0) return;

        if (x == m - 1 && y == n - 1) {
            ans.push_back(currentPath);
            return;
        }

        maze[x][y] = 0;

        currentPath.push_back('D');
        generate(maze, x + 1, y, currentPath);
        currentPath.pop_back();

        currentPath.push_back('L');
        generate(maze, x, y - 1, currentPath);
        currentPath.pop_back();

        currentPath.push_back('R');
        generate(maze, x, y + 1, currentPath);
        currentPath.pop_back();

        currentPath.push_back('U');
        generate(maze, x - 1, y, currentPath);
        currentPath.pop_back();

        maze[x][y] = 1;
    }

public:
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        // Your code goes here
        string currentPath("");

        generate(maze, 0, 0, currentPath);

        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends