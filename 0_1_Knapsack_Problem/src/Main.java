//{ Driver Code Starts

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class gfg {
    public static void main(String[] args) throws IOException {
        //reading input using BufferedReader class
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        //reading total testcases
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            //reading number of elements and weight
            int n = Integer.parseInt(read.readLine());
            int w = Integer.parseInt(read.readLine());

            int[] val = new int[n];
            int[] wt = new int[n];

            String[] st = read.readLine().trim().split("\\s+");

            //inserting the values
            for (int i = 0; i < n; i++)
                val[i] = Integer.parseInt(st[i]);

            String[] s = read.readLine().trim().split("\\s+");

            //inserting the weigths
            for (int i = 0; i < n; i++)
                wt[i] = Integer.parseInt(s[i]);

            //calling method knapSack() of class Knapsack
            System.out.println(new Solution().knapSack(w, wt, val, n));
        }
    }
}




// } Driver Code Ends


class Solution {
    //Function to return max value that can be put in knapsack of capacity W.
    public int knapSack(int maxWeight, int[] wt, int[] val, int n) {
        // your code here
        int[] dp = new int[maxWeight + 1];

        for (int i = 0; i < n; ++i) {
            for (int w = maxWeight; w > 0; --w) {
                if (wt[i] <= w) dp[w] = Math.max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }

        return dp[maxWeight];
    }
}


