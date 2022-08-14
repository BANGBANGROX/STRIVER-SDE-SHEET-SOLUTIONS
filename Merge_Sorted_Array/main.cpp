#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> ans(m + n);

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ans[k] = nums1[i];
                ++i;
            }
            else {
                ans[k] = nums2[j];
                ++j;
            }
            ++k;
        }

        while (i < m) {
            ans[k] = nums1[i];
            ++i;
            ++k;
        }

        while (j < n) {
            ans[k] = nums2[j];
            ++j;
            ++k;
        }

        nums1 = ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<int> nums1(m + n);
        for (int i = 0; i < m; ++i) {
            cin >> nums1[i];
        }
        vector<int> nums2(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums2[i];
        }

        Solution solution;
        solution.merge(nums1, m, nums2, n);
        for (int x : nums1) cout << x << " ";
        cout << endl;
    }

    return 0;
}
