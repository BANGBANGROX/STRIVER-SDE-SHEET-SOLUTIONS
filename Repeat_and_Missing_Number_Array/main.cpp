#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> repeatedNumber(const vector<int> &nums) {
        int x = 0;
        int y = 0;
        int xorResult = 0;
        int n = nums.size();

        for (int num: nums) {
            xorResult ^= num;
        }

        for (int i = 1; i <= n; ++i) {
            xorResult ^= i;
        }

        int setBit = xorResult & ~(xorResult - 1);

        for (int i = 0; i < n; ++i) {
            if ((nums[i] & setBit) > 0) x ^= nums[i];
            else y ^= nums[i];
        }

        for (int i = 1; i <= n; ++i) {
            if ((i & setBit) > 0) x ^= i;
            else y ^= i;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] == x) return {x, y};
        }

        return {y, x};
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
        vector<int> ans = solution.repeatedNumber(nums);
        cout << ans[0] << " " << ans[1] << endl;
    }
}
