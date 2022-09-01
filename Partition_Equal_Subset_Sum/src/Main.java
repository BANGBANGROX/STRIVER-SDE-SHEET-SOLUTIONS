import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public boolean canPartition(int[] nums) {
        int totalSum = Arrays.stream(nums).sum();

        if ((totalSum & 1) > 0) return false;

        boolean[] dp = new boolean[totalSum / 2 + 1];

        dp[0] = true;

        for (int num: nums) {
            for (int sum = totalSum / 2; sum >= num; --sum) {
                dp[sum] |= dp[sum - num];
            }
        }

        return dp[totalSum / 2];
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

            Solution solution = new Solution();
            System.out.println(solution.canPartition(nums));
        }

        sc.close();
    }
}
