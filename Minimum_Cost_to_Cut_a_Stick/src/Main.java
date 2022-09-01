import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Solution {
    public int minCost(int rodLength, int[] cuts) {
        int n = cuts.length;
        ArrayList<Integer> cutsList = new ArrayList<>();
        int[][] dp = new int[n + 2][n + 2];

        for (int cut: cuts) {
            cutsList.add(cut);
        }

        cutsList.add(0);
        cutsList.add(rodLength);
        Collections.sort(cutsList);

        for (int i = n; i >= 1; --i) {
            for (int j = i; j <= n; ++j) {
                int res = Integer.MAX_VALUE;
                for (int k = i; k <= j; ++k) {
                    res = Math.min(res, cutsList.get(j + 1) -
                            cutsList.get(i - 1) + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = res;
            }
        }

        return dp[1][n];
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int rodLength = sc.nextInt();
            int n = sc.nextInt();
            int[] cuts = new int[n];
            for (int i = 0; i < n; ++i) {
                cuts[i] = sc.nextInt();
            }

            Solution solution = new Solution();
            System.out.println(solution.minCost(rodLength, cuts));
        }

        sc.close();
    }
}
