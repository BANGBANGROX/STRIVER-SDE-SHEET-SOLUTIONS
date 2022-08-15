#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;

        nums.push_back(0);

        for (int num : nums) {
            if (num == 1) {
                ++cnt;
            }
            else {
                ans = max(ans, cnt);
                cnt = 0;
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
        cout << solution.findMaxConsecutiveOnes(nums) << endl;
    }

    return 0;
}
