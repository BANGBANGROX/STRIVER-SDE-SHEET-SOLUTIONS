#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prevSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[i] <= nums[st.top()]) st.pop();
            ans[i] = (st.empty() ? -1 : nums[st.top()]);
            st.push(i);
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
        vector<int> ans = solution.prevSmaller(nums);
        for (int &x: ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}
