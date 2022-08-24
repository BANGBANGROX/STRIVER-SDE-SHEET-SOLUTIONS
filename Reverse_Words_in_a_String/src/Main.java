import java.util.Scanner;

class Solution {
    public String reverseWords(String s) {
         int n = s.length();
         StringBuilder ans = new StringBuilder();

         for (int i = 0; i < n; ++i) {
             StringBuilder currentWord = new StringBuilder();
             while (i < n && s.charAt(i) != ' ') {
                 currentWord.append(s.charAt(i));
                 ++i;
             }
             if (currentWord.length() == 0) continue;
             if (ans.length() == 0) ans.insert(0, currentWord);
             else ans.insert(0, currentWord.toString() + ' ');
         }

         return ans.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            String s = sc.nextLine();

            Solution solution = new Solution();
            System.out.println(solution.reverseWords(s));
        }

        sc.close();
    }
}
