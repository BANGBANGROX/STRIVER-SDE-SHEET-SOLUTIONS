import java.util.ArrayList;
import java.util.Scanner;

class Solution {
    private int lowerBound(ArrayList<Integer> nums, int key) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (nums.get(mid) < key) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }

    public int lengthOfLIS(int[] nums) {
        ArrayList<Integer> dp = new ArrayList<>();

        for (int num: nums) {
            if (dp.isEmpty() || dp.get(dp.size() - 1) < num) dp.add(num);
            else {
                int idx = lowerBound(dp, num);
                dp.set(idx, num);
            }
        }

        return dp.size();
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
            System.out.println(solution.lengthOfLIS(nums));
        }

        sc.close();
    }
}
