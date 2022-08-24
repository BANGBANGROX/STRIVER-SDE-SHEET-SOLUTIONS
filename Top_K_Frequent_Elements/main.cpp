#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
         unordered_map<int, int> count;
         vector<int> ans;
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

         for (int num: nums) {
             ++count[num];
         }

         for (int num: nums) {
             if (count[num] == 0) continue;
             if (pq.size() < k) {
                 pq.push({count[num], num});
             }
             else {
                 if (count[num] > pq.top().first) {
                     pq.pop();
                     pq.push({count[num], num});
                 }
             }
         }

         while (!pq.empty()) {
             ans.push_back(pq.top().second);
             pq.pop();
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
        int k;
        cin >> k;

        Solution solution;
        vector<int> ans = solution.topKFrequent(nums, k);
        for (int &x: ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}
