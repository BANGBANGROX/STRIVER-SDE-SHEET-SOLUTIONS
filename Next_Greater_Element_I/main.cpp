#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
         unordered_map<int, int> index;
         stack<int> st;
         int m = nums1.size();
         int n = nums2.size();
         vector<int> ans(m);
         vector<int> nums2Result(n);

         for (int i = n - 1; i >= 0; --i) {
             while (!st.empty() && nums2[i] >= nums2[st.top()]) {
                 st.pop();
             }
             nums2Result[i] = (st.empty() ? -1 : nums2[st.top()]);
             st.push(i);
             index[nums2[i]] = i;
         }

         for (int i = 0; i < m; ++i) {
             ans[i] = nums2Result[index[nums1[i]]];
         }

         return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m;
        cin >> m;
        vector<int> nums1(m);
        for (int &x: nums1) cin >> x;
        int n;
        cin >> n;
        vector<int> nums2(n);
        for (int &x: nums2) cin >> x;

        Solution solution;
        vector<int> ans = solution.nextGreaterElement(nums1, nums2);
        for (int &x: ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}
