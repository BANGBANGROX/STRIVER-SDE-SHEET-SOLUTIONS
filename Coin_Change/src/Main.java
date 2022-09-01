import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public int coinChange(int[] coins, int amount) {
         int[] dp = new int[amount + 1];

        Arrays.fill(dp, Integer.MAX_VALUE);

        dp[0] = 0;

        for (int coin: coins) {
            for (int amt = coin; amt <= amount; ++amt) {
                if (dp[amt - coin] != Integer.MAX_VALUE) {
                    dp[amt] = Math.min(dp[amt], dp[amt - coin] + 1);
                }
            }
        }

        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int n = sc.nextInt();
            int[] coins = new int[n];
            for (int i = 0; i < n; ++i) {
                coins[i] = sc.nextInt();
            }
            int amount = sc.nextInt();

            Solution solution = new Solution();
            System.out.println(solution.coinChange(coins, amount));
        }

        sc.close();
    }
}
