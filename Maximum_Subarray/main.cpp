#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int num : nums) {
            currentSum = max(currentSum + num, num);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
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
        cout << solution.maxSubArray(nums) << endl;
    }
}
