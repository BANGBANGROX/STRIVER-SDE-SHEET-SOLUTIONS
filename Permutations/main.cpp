#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool nextPermutation(vector<int> &nums) {
        int n = nums.size();

        if (n == 1) return false;

        int last = n - 2;

        while (last >= 0 && nums[last + 1] <= nums[last]) --last;

        if (last < 0) return false;

        int nextGreater = n - 1;

        for (int i = n - 1; i > last; --i) {
            if (nums[last] < nums[i]) {
                nextGreater = i;
                break;
            }
        }

        swap(nums[last], nums[nextGreater]);
        reverse(nums.begin() + last + 1, nums.end());

        return true;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        do {
            ans.push_back(nums);
        } while (nextPermutation(nums));

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
        vector<vector<int>> ans = solution.permute(nums);
        for (vector<int> &x: ans) {
            for (int &y: x) cout << y << " ";
            cout << endl;
        }
    }

    return 0;
}
