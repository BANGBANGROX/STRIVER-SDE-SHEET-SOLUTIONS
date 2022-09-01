//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String str = in.readLine();
            Solution ob = new Solution();
            System.out.println(ob.palindromicPartition(str));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    public int palindromicPartition(String s) {
        // code here
        int n = s.length();
        boolean[][] isPalindrome = new boolean[n][n];
        int[] dp = new int[n];

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (i == j) {
                    isPalindrome[i][j] = true;
                    continue;
                }
                boolean b = s.charAt(i) == s.charAt(j);
                if (len == 2) {
                    isPalindrome[i][j] = b;
                } else {
                    isPalindrome[i][j] = (b && isPalindrome[i + 1][j - 1]);
                }
            }
        }

        Arrays.fill(dp, Integer.MAX_VALUE);

        for (int i = 0; i < n; ++i) {
            if (isPalindrome[0][i]) {
                dp[i] = 1;
                continue;
            }
            for (int j = 0; j < i; ++j) {
                if (isPalindrome[j + 1][i] && dp[j] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], 1 + dp[j]);
                }
            }
        }

        return dp[n - 1] - 1;
    }
}