#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1;

        while (i < n) {
            if (nums[i] != nums[i - 1]) {
                ++i;
            }
            else {
                int idx = i - 1;
                while (i < n && nums[i] == nums[idx]) {
                    nums[i] = -101;
                    ++i;
                }
            }
        }

        int l = 0;

        while (l < n && nums[l] != -101) {
            ++l;
        }

        if (l == n) return n;

        int r = l + 1;

        for (; r < n; ++r) {
            if (nums[r] == -101) continue;
            swap(nums[l], nums[r]);
            while (nums[l] != -101) {
                ++l;
            }
        }

        i = 0;

        while (nums[i] != -101) {
            ++i;
        }

        return i;
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
        int k = solution.removeDuplicates(nums);

        for (int i = 0; i < k; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
