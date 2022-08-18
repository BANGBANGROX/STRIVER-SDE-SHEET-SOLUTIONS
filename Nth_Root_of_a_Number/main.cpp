#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(double num, double m, int n) {
        double res = 1;

        for (int i = 1; i <= n; ++i) {
            res = res * num;
            if (res > m) return false;
        }

        return true;
    }

public:
    double nthRoot(int n, int m) {
        if (n == 1) return m;

        double l = 1;
        double r = m;
        double diff = 1e-6;

        while ((r - l) > diff) {
            double mid = (l + r) / 2;
            if (check(mid, m, n)) l = mid;
            else r = mid;
        }

        return l;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        Solution solution;
        cout << solution.nthRoot(n, m) << endl;
    }

    return 0;
}
