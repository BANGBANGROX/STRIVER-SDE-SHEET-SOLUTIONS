#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct comparator {
        bool operator()(const vector<int> &a, const vector<int> &b) const{
            return a[0] > b[0];
        }
    };
public:
    vector<int> solve(vector<int> &nums1, vector<int> &nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int count = 0;
        vector<int> ans;
        priority_queue<vector<int>, vector<vector<int>>, comparator> pq;
        set<vector<int>> visited;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        pq.push({nums1[m - 1] + nums2[n - 1], m - 1, n - 1});
        visited.insert({m - 1, n - 1});

        while (count < k) {
            vector<int> current = pq.top();
            pq.pop();
            ans.push_back(current[0]);
            int i = current[1];
            int j = current[2];
            vector<int> first = {i - 1, j};
            vector<int> second = {i, j - 1};
            if (visited.find(first) == visited.end()) {
                pq.push({nums1[i - 1] + nums2[j], i - 1, j});
                visited.insert(first);
            }
            if (visited.find(second) == visited.end()) {
                pq.push({nums1[i] + nums2[j - 1], i, j - 1});
                visited.insert(second);
            }
            ++count;
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
        vector<int> nums1(n);
        for (int &x: nums1) cin >> x;
        vector<int> nums2(n);
        for (int &x: nums2) cin >> x;
        int k;
        cin >> k;

        Solution solution;
        vector<int> ans = solution.solve(nums1, nums2, k);
    }

    return 0;
}
