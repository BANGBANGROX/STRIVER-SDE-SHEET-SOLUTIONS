#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int candidate = nums[0];

        for (int i = 1; i < n; ++i) {
            if (count == 0) {
                candidate = nums[i];
                ++count;
            }
            if (nums[i] == candidate) ++count;
            else {
                --count;
            }
        }

        return candidate;
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
        cout << solution.majorityElement(nums) << endl;
    }

    return 0;
}
