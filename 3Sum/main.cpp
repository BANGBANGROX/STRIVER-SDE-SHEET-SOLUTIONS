#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> visited;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            int target = - 1 * nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    vector<int> current = {nums[i], nums[l], nums[r]};
                    if (visited.find(current) == visited.end()) {
                        visited.insert(current);
                        ans.push_back(current);
                    }
                    ++l;
                    --r;
                }
                else if (sum > target) --r;
                else ++l;
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

        Solution solution;
        vector<vector<int>> ans = solution.threeSum(nums);
        for (vector<int> &x: ans) {
            cout << x[0] << " " << x[1] << " " << x[2] << endl;
        }
    }

    return 0;
}
