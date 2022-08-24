#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;

        for (int num: nums) {
            if (pq.size() < k) pq.push(num);
            else {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }

        return pq.top();
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
        cout << solution.findKthLargest(nums) << endl;
    }

    return 0;
}
