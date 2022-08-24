import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int ans = 0;
        int[] leftSmaller = new int[n];
        int[] rightSmaller = new int[n];
        Stack<Integer> st = new Stack<>();

        Arrays.fill(rightSmaller, n - 1);

        for (int i = 0; i < n; ++i) {
            while (!st.isEmpty() && heights[st.peek()] >= heights[i]) st.pop();
            if (!st.isEmpty()) leftSmaller[i] = st.peek() + 1;
            st.push(i);
        }

        st.clear();

        for (int i = n - 1; i >= 0; --i) {
            while (!st.isEmpty() && heights[st.peek()] >= heights[i]) st.pop();
            if (!st.isEmpty()) rightSmaller[i] = st.peek() - 1;
            st.push(i);
        }

        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, heights[i] * (rightSmaller[i] - leftSmaller[i] + 1));
        }

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int n = sc.nextInt();
            int[] heights = new int[n];
            for (int i = 0; i < n; ++i) {
                heights[i] = sc.nextInt();
            }

            Solution solution = new Solution();
            System.out.println(solution.largestRectangleArea(heights));
        }

        sc.close();
    }
}
