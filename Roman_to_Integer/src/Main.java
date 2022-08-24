import java.util.HashMap;
import java.util.Scanner;

class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int ans = 0;

        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);

        for (int i = 0; i < s.length(); ++i) {
            if (i + 1 < s.length() && mp.get(s.charAt(i + 1)) > mp.get(s.charAt(i))) {
                ans += (mp.get(s.charAt(i + 1)) - mp.get(s.charAt(i)));
                ++i;
            }
            else {
                ans += mp.get(s.charAt(i));
            }
        }

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            String s = sc.next();

            Solution solution = new Solution();
            System.out.println(solution.romanToInt(s));
        }

        sc.close();
    }
}
