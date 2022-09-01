//{ Driver Code Starts
//Initial Template for Java

import java.util.*;

class GfG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] Arr = new int[n];
            for (int i = 0; i < n; i++)
                Arr[i] = sc.nextInt();
            Solution ob = new Solution();
            System.out.println(ob.maxSumIS(Arr, n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    public int maxSumIS(int[] nums, int n) {
        //code here.
        int[] dp = new int[n];

        for (int i = 0; i < n; ++i) {
            int maxVal = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) maxVal = Math.max(maxVal, dp[j]);
            }
            dp[i] = maxVal + nums[i];
        }

        return Arrays.stream(dp).max().getAsInt();
    }
}