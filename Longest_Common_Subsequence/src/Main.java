import java.util.Scanner;

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
          int m = text1.length();
          int n = text2.length();
          int[][] dp = new int[m + 1][n + 1];

          for (int i = 1; i <= m; ++i) {
              for (int j = 1; j <= n; ++j) {
                  if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                      dp[i][j] = 1 + dp[i - 1][j - 1];
                  }
                  else {
                      dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                  }
              }
          }

          return dp[m][n];
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            String text1 = sc.next();
            String text2 = sc.next();

            Solution solution = new Solution();
            System.out.println(solution.longestCommonSubsequence(text1, text2));
        }

        sc.close();
    }
}
