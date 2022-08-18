#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int> &positions, int distance, int cows) {
        int currentCows = 1;
        int pos = positions[0];
        int n = positions.size();

        for (int i = 1; i < n; ++i) {
            if (positions[i] - pos < distance) continue;
            ++currentCows;
            pos = positions[i];
            if (currentCows == cows) return true;
        }

        return false;
    }

public:
    int minDistance(vector<int> &positions, int cows) {
        sort(positions.begin(), positions.end());

        int l = 1;
        int r = positions.back() - positions[0];
        int ans = -1;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (check(positions, mid, cows)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, cows;
        cin >> n >> cows;
        vector<int> positions(n);
        for (int &x: positions) cin >> x;

        Solution solution;
        cout << solution.minDistance(positions, cows) << endl;
    }

    return 0;
}
