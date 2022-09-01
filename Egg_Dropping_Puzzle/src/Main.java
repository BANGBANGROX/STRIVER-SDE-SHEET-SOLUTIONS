//{ Driver Code Starts
import java.lang.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        //reading input using BufferedReader class
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //reading total testcases
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {

            //reading number of eggs and floors
            String[] inputLine = br.readLine().trim().split(" ");

            int n = Integer.parseInt(inputLine[0]);
            int k = Integer.parseInt(inputLine[1]);

            //calling eggDrop() method of class
            //EggDrop
            System.out.println(new Solution().eggDrop(n, k));
        }
    }
}



// } Driver Code Ends


class Solution {
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    public int eggDrop(int n, int k) {
        // Your code here
        int ans = 0;
        int[] dp1 = new int[n + 1];
        int[] dp2 = new int[n + 1];

        if (n == 1) return k;

        while (dp1[n] < k) {
            ++ans;
            for (int i = 1; i <= n; ++i) {
                dp2[i] = dp1[i] + dp1[i - 1] + 1;
            }
            dp1 = dp2.clone();
        }

        return ans;
    }
}