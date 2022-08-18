//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool isSafe(int node, bool graph[101][101], vector<int> &color, int c, int n) {
        for (int i = 0; i < n; ++i) {
            if (node != i && graph[node][i] && color[i] == c) return false;
        }

        return true;
    }
    bool graphColoringUtil(int node, bool graph[101][101], vector<int> &color, int m,
                           int n) {
        if (node == n) return true;

        for (int c = 0; c < m; ++c) {
            color[node] = c;
            if (isSafe(node, graph, color, c, n)) {
                if (graphColoringUtil(node + 1, graph, color, m, n)) return true;
            }
            color[node] = -1;
        }

        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n, -1);

        return graphColoringUtil(0, graph, color, m, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends