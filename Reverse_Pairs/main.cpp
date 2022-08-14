#include<bits/stdc++.h>
using namespace std;

class Solution {
    int merge(vector<int>& temp, vector<int>& nums, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int k = left;
        int ans = 0;

        for (; i <= mid; ++i) {
            while (j <= right && nums[i] > 1LL * 2 * nums[j]) ++j;
            ans += (j - (mid + 1));
        }

        i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k] = nums[i];
                ++i;
            }
            else {
                temp[k] = nums[j];
                ++j;
            }
            ++k;
        }

        while (i <= mid) {
            temp[k] = nums[i];
            ++i;
            ++k;
        }

        while (j <= right) {
            temp[k] = nums[j];
            ++j;
            ++k;
        }

        for (i = left; i <= right; ++i) {
            nums[i] = temp[i];
        }

        return ans;
    }

    int mergeSort(vector<int>& temp, vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = (left + ((right - left) >> 1));
        int ans = 0;

        ans += mergeSort(temp, nums, left, mid);
        ans += mergeSort(temp, nums, mid + 1, right);
        ans += merge(temp, nums, left, mid, right);

        return ans;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);

        return mergeSort(temp, nums, 0, n - 1);
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
        cout << solution.reversePairs(nums) << endl;
    }
}
