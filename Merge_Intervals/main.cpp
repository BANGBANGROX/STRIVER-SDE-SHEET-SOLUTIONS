#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         int n = intervals.size();
         vector<vector<int>> ans;

         sort(intervals.begin(), intervals.end());

         ans.push_back(intervals[0]);

         for (int i = 1; i < n; ++i) {
             int l1 = ans.back()[0];
             int r1 = ans.back()[1];
             int l2 = intervals[i][0];
             int r2 = intervals[i][1];
             if (l2 <= r1) {
                 ans.pop_back();
                 ans.push_back({l1, max(r1, r2)});
             }
             else ans.push_back({l2, r2});
         }

         return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            cin >> intervals[i][0] >> intervals[i][1];
        }

        Solution solution;
        vector<vector<int>> ans = solution.merge(intervals);
        for (vector<int> &x: ans) {
            for (int &y: x) cout << y << " ";
            cout << endl;
        }
    }
}
