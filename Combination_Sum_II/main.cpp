#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    set<vector<int>> visited;

    void generate(vector<int> &nums, vector<int> &currentResult, int target, int index) {
        if (target == 0) {
            if (visited.find(currentResult) == visited.end()) {
                 ans.push_back(currentResult);
                 visited.insert(currentResult);
            }
            return;
        }

        if (index >= (int) nums.size()) return;

        for (int i = index; i < (int) nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            if (target < nums[i]) return;
            currentResult.push_back(nums[i]);
            generate(nums, currentResult, target - nums[i], i + 1);
            currentResult.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(), candidates.end());

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
        vector<vector<int>> ans = solution.combinationSum2(nums, target);
        for (vector<int> &x: ans) {
            for (int &y: x) cout << y << " ";
            cout << endl;
        }
    }

    return 0;
}
