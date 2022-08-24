import java.util.Scanner;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String minLengthString = strs[0];
        int n = strs.length;

        for (int i = 1; i < n; ++i) {
            if (strs[i].length() < minLengthString.length()) {
                minLengthString = strs[i];
            }
        }

        int len = minLengthString.length();
        int minMatchingLength = len;

        for (String str : strs) {
            int j = 0;
            while (j < len && str.charAt(j) == minLengthString.charAt(j)) {
                ++j;
            }
            minMatchingLength = Math.min(minMatchingLength, j);
        }

        return minLengthString.substring(0, minMatchingLength);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int n = sc.nextInt();
            String[] strs = new String[n];
            for (int i = 0; i < n; ++i) {
                strs[i] = sc.next();
            }

            Solution solution = new Solution();
            System.out.println(solution.longestCommonPrefix(strs));
        }

        sc.close();
    }
}
