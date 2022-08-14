#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indexes;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (indexes.find(target - nums[i]) != indexes.end()) {
                return {indexes[target - nums[i]], i};
            }
            indexes[nums[i]] = i;
        }

        return {};
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
        vector<int> ans = solution.twoSum(nums, target);
        cout << ans[0] << " " << ans[1] << endl;
    }

    return 0;
}
