#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return;

        int last = n - 2;

        while (last >= 0 && nums[last + 1] <= nums[last]) --last;

        if (last < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int nextGreater = n - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (nums[last] < nums[i]) {
                nextGreater = i;
                break;
            }
        }

        swap(nums[last], nums[nextGreater]);
        reverse(nums.begin() + last + 1, nums.end());
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
        solution.nextPermutation(nums);
        for (int &x: nums) cout << x << " ";
        cout << endl;
    }

    return 0;
}
