//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(in.readLine());
            String[] input_line = in.readLine().trim().split("\\s+");
            int[] arr = new int[N];
            for (int i = 0; i < N; i++)
                arr[i] = Integer.parseInt(input_line[i]);

            Solution ob = new Solution();
            System.out.println(ob.matrixMultiplication(N, arr));
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    private int[] sizes;
    private int[][] dp;

    private int matrixMultiplicationUtil(int i, int j) {
        if (i >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = Integer.MAX_VALUE;

        for (int k = i; k < j; ++k) {
            ans = Math.min(ans, matrixMultiplicationUtil(i, k) +
                    matrixMultiplicationUtil(k + 1, j) + sizes[i - 1] * sizes[k] * sizes[j]);
        }

        return dp[i][j] = ans;
    }

    public int matrixMultiplication(int n, int[] sizes) {
        // code here
        this.sizes = sizes;
        dp = new int[n][n];

        for (int i = 0; i < n; ++i) {
            Arrays.fill(dp[i], -1);
        }

        return matrixMultiplicationUtil(1, n - 1);
    }
}