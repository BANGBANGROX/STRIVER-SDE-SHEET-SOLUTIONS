#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = m;

        while (l <= r) {
            int cut1 = (l + r) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            int a1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int a2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int b1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int b2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            if (a1 <= b2 && a2 <= b1) {
                if ((m + n) % 2 == 0) return (max(a1, a2) + min(b1, b2)) / 2.0;
                return max(a1, a2);
            }
            else if (a1 > b2) r = cut1 - 1;
            else l = cut1 + 1;
        }

        return -1;
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
        cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    }

    return 0;
}
