#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        bool sign = (n > 0);
        n = abs(n);

        while (n > 0) {
            if ((n & 1) > 0) {
                ans = (ans * x);
                --n;
            }
            x = x * x;
            n /= 2;
        }

        if (!sign) ans = 1 / ans;

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        double x;
        cin >> x;
        int n;
        cin >> n;

        Solution solution;
        cout << solution.myPow(x, n) << endl;
    }
}
