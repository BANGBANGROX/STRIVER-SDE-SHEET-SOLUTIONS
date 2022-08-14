#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int minPrice = prices[0];
         int n = prices.size();
         int ans = 0;

         for (int i = 1; i < n; ++i) {
             ans = max(ans, prices[i] - minPrice);
             minPrice = min(minPrice, prices[i]);
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
        vector<int> prices(n);
        for (int &x: prices) cin >> x;

        Solution solution;
        cout << solution.maxProfit(prices) << endl;
    }

    return 0;
}
