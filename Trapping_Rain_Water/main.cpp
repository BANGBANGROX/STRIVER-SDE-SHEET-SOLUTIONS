#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
         int l = 0;
         int r = n - 1;
         int lMax = 0;
         int rMax = 0;
         int ans = 0;

         while (l < r) {
             lMax = max(lMax, height[l]);
             rMax = max(rMax, height[r]);
             if (lMax < rMax) {
                 ans += (lMax - height[l]);
                 ++l;
             }
             else {
                 ans += (rMax - height[r]);
                 --r;
             }
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
        vector<int> height(n);
        for (int &x: height) cin >> x;

        Solution solution;
        cout << solution.trap(height) << endl;
    }

    return 0;
}
