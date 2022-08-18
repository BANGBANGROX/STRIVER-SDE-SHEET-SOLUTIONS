#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;

    void generate(vector<int> &nums, vector<int> &currentResult, int target, int index) {
         if (target == 0) {
             ans.push_back(currentResult);
             return;
         }

         if (index == (int) nums.size()) return;

         generate(nums, currentResult, target, index + 1);

         if (nums[index] <= target) {
             currentResult.push_back(nums[index]);
             generate(nums, currentResult, target - nums[index], index);
             currentResult.pop_back();
         }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<int> currentResult;

          generate(candidates, currentResult, target, 0);

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
        vector<vector<int>> ans = solution.combinationSum(nums, target);
        for (vector<int> &x: ans) {
            for (int &y: x) cout << y << " ";
            cout << endl;
        }
    }

    return 0;
}
