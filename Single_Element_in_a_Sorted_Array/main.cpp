#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
         int n = nums.size();
         int l = 0;
         int r = n - 2;

         while (l <= r) {
             int mid = (l + ((r - l) >> 1));
             if ((mid & 1) == 0) {
                 if (nums[mid] == nums[mid + 1]) l = mid + 1;
                 else r = mid - 1;
             }
             else {
                 if (nums[mid] == nums[mid + 1]) r = mid - 1;
                 else l = mid + 1;
             }
         }

         return nums[l];
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
        cout << solution.singleNonDuplicate(nums) << endl;
    }

    return 0;
}
