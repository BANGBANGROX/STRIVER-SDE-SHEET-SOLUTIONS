#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        if (nums[l] == target) return l;

        if (nums[r] == target) return r;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[0]) {
                if (target <= nums[mid] && target >= nums[0]) r = mid - 1;
                else l = mid + 1;
            }
            else {
                if (target >= nums[mid] && target <= nums[n - 1]) l = mid + 1;
                else r = mid - 1;
            }
        }

        return -1;
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
        cout << solution.search(nums, target) << endl;
    }

    return 0;
}
