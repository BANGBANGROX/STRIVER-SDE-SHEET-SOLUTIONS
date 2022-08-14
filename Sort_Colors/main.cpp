#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        int idx = 0;

        for (int num : nums) {
            ++count[num];
        }

        for (int i = 0; i < 3; ++i) {
            while (count[i] > 0) {
                nums[idx] = i;
                --count[i];
                ++idx;
            }
        }
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
        solution.sortColors(nums);
        for (int &x: nums) cout << x << " ";
        cout << endl;
    }

    return 0;
}
