#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
          vector<vector<int>> ans;
          set<vector<int>> visited;
          int n = nums.size();

          sort(nums.begin(), nums.end());

          for (int i = 0; i < n - 3; ++i) {
              long currentTarget = target - nums[i];
              for (int j = i + 1; j < n - 2; ++j) {
                  long requiredTarget = currentTarget - nums[j];
                  int l = j + 1;
                  int r = n - 1;
                  while (l < r) {
                      long sum = nums[l] + nums[r];
                      if (sum == requiredTarget) {
                          vector<int> currentResult = {nums[i], nums[j], nums[l], nums[r]};
                          if (visited.find(currentResult) == visited.end()) {
                              ans.push_back(currentResult);
                              visited.insert(currentResult);
                          }
                          ++l;
                          --r;
                      }
                      else if (sum > requiredTarget) --r;
                      else ++l;
                  }
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
        vector<int> nums(n);
        for (int &x: nums) cin >> x;
        int target;
        cin >> target;

        Solution solution;
        vector<vector<int>> ans = solution.fourSum(nums, target);
        for (vector<int> &x: ans) {
            for (int &y: x) cout << y << " ";
            cout << endl;
        }
    }

    return 0;
}
