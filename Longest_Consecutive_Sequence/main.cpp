#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> visited(nums.begin(), nums.end());
        int ans = 1;
        int n = nums.size();

        if (n == 0) return 0;

        for (int num : nums) {
            if (visited.find(num - 1) != visited.end()) continue;
            int currentLength = 0;
            while (visited.find(num) != visited.end()) {
                visited.erase(num);
                ++currentLength;
                ++num;
            }
            ans = max(ans, currentLength);
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
        cout << solution.longestConsecutive(nums) << endl;
    }

    return 0;
}
