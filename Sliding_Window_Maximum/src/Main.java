import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        int idx = 0;

        for (int i = 0; i < k; ++i) {
            while (!dq.isEmpty() && nums[dq.getLast()] < nums[i]) dq.pollLast();
            dq.add(i);
        }

        for (int i = k; i < n; ++i) {
            ans[idx++] = nums[dq.getFirst()];
            while (!dq.isEmpty() && dq.getFirst() <= i - k) dq.pollFirst();
            while (!dq.isEmpty() && nums[dq.getLast()] < nums[i]) dq.pollLast();
            dq.add(i);
        }

        ans[idx] = nums[dq.getFirst()];

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int n = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; ++i) {
                nums[i] = sc.nextInt();
            }
            int k = sc.nextInt();

            Solution solution = new Solution();
            int[] ans = solution.maxSlidingWindow(nums, k);
            for (int x: ans) {
                System.out.print(x + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
