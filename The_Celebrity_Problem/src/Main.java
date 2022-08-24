//{ Driver Code Starts
//Initial Template for Java

import java.util.Scanner;
import java.util.Stack;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int N = sc.nextInt();
            int[][] M = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    M[i][j] = sc.nextInt();
                }
            }
            System.out.println(new Solution().celebrity(M, N));
            t--;
        }
    }
}
// } Driver Code Ends


//User function Template for Java


class Solution {
    //Function to find if there is a celebrity in the party or not.
    int celebrity(int[][] matrix, int n) {
        // code here
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; ++i) {
            st.push(i);
        }

        while (st.size() > 1) {
            int a = st.pop();
            int b = st.pop();
            if (matrix[a][b] > 0) st.push(b);
            else if (matrix[b][a] > 0) st.push(a);
        }

        if (st.isEmpty()) return -1;

        int potentialCelebrity = st.peek();
        int knowsPeople = 0;
        int knownByPeople = 0;

        for (int i = 0; i < n; ++i) {
            if (matrix[potentialCelebrity][i] > 0) ++knowsPeople;
        }

        for (int i = 0; i < n; ++i) {
            if (matrix[i][potentialCelebrity] > 0) ++knownByPeople;
        }

        return (knowsPeople == 0 && knownByPeople == n - 1 ? potentialCelebrity : -1);
    }
}