#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int target) {
        int currentXor = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> count;

        for (int i = 0; i < n; ++i)  {
            currentXor ^= nums[i];
            if (currentXor == target) ++ans;
            if (count.find(currentXor ^ target) != count.end()) {
                ans += count[currentXor ^ target];
            }
            ++count[currentXor];
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
        int target;
        cin >> target;

        Solution solution;
        cout << solution.solve(nums, target) << endl;
    }

    return 0;
}
