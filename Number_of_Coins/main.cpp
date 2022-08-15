//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int minCoins(int coins[], int n, int target) {
	    // Your code goes here
        vector<int> dp(target + 1, INT_MAX);

        dp[0] = 0;

        for (int sum = 1; sum <= target; ++sum) {
            for (int i = 0; i < n; ++i) {
                if (coins[i] <= sum && dp[sum - coins[i]] != INT_MAX)
                    dp[sum] = min(dp[sum], dp[sum - coins[i]] + 1);
            }
        }

        return dp[target] == INT_MAX ? -1 : dp[target];
	}
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends