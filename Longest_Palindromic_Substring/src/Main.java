import java.util.Scanner;

class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int start = -1;
        int end = -1;
        boolean[][] dp = new boolean[n][n];


        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (len == 1) dp[i][j] = true;
                else {
                    final boolean b = s.charAt(i) == s.charAt(j);
                    if (len == 2) dp[i][j] = b;
                    else dp[i][j] = (b && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && len >= (end - start + 1)) {
                    start = i;
                    end = j;
                }
            }
        }

        return s.substring(start, end + 1);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            String s = sc.next();

            Solution solution = new Solution();
            System.out.println(solution.longestPalindrome(s));
        }

        sc.close();
    }
}
