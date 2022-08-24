//{ Driver Code Starts
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String[] inputline = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputline[0]);
            inputline = br.readLine().trim().split(" ");
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputline[i]);
            }
            Solution ob =new Solution();
            int[] res = ob.maxOfMin(arr, n);

            for (int i = 0; i < n; i++)
                System.out.print (res[i] + " ");
            System.out.println ();
        }
    }
}
// } Driver Code Ends



class Solution {
    private int[] nextSmaller(int[] nums, int n) {
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = n - 1; i >= 0; --i) {
            while (!st.isEmpty() && nums[st.peek()] >= nums[i]) st.pop();
            ans[i] = (st.isEmpty() ? n : st.peek());
            st.push(i);
        }

        return ans;
    }

    private int[] previousSmaller(int[] nums, int n) {
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; ++i) {
            while (!st.isEmpty() && nums[st.peek()] >= nums[i]) st.pop();
            ans[i] = (st.isEmpty() ? -1 : st.peek());
            st.push(i);
        }

        return ans;
    }

    //Function to find maximum of minimums of every window size.
    public int[] maxOfMin(int[] nums, int n) {
        // Your code here
        int[] left = previousSmaller(nums, n);
        int[] right = nextSmaller(nums, n);
        int[] ans = new int[n];

        for (int i = 0; i < n; ++i) {
            int len = right[i] - left[i] - 1;
            if (len > 0) {
                ans[len - 1] = Math.max(ans[len - 1], nums[i]);
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            ans[i] = Math.max(ans[i], ans[i + 1]);
        }

        return ans;
    }
}