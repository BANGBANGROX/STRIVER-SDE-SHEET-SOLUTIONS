import java.util.Scanner;

class Solution {
    public int myAtoi(String s) {
        int ans = 0;
        int sign = 1;
        int i = 0;
        int n = s.length();

        while (i < n && s.charAt(i) == ' ') ++i;

        if (i == n) return 0;

        if (s.charAt(i) == '+') {
            if (i == n - 1) return 0;
            ++i;
            if (!Character.isDigit(s.charAt(i))) return 0;
        }
        if (s.charAt(i) == '-') {
            sign = -1;
            ++i;
        }

        while (i < n && Character.isDigit(s.charAt(i))) {
            int digit = s.charAt(i) - '0';
            if (ans > Integer.MAX_VALUE / 10 ||
                    (ans == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE % 10)) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            ans = ans * 10 + digit;
            ++i;
        }

        return sign * ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            String s = sc.next();

            Solution solution = new Solution();
            System.out.println(solution.myAtoi(s));
        }

        sc.close();
    }
}
