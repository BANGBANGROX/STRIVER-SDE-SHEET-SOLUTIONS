import java.util.*;

class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int ans = 0;
        int[] dx = {-1, 0, 0, 1};
        int[] dy = {0, 1, -1, 0};
        Queue<ArrayList<Integer>> q = new LinkedList<>();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.add(new ArrayList<>(Arrays.asList(i, j)));
            }
        }

        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                ArrayList<Integer> cell = q.poll();
                assert cell != null;
                int x = cell.get(0);
                int y = cell.get(1);
                for (int j = 0; j < 4; ++j) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                            grid[newX][newY] == 1) {
                        q.add(new ArrayList<>(Arrays.asList(newX, newY)));
                        grid[newX][newY] = 2;
                    }
                }
            }
            ++ans;
        }

        for (int[] ints : grid) {
            for (int j = 0; j < n; ++j) {
                if (ints[j] == 1) return -1;
            }
        }

        return ans > 0 ? ans -1 : 0;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int m = sc.nextInt();
            int n = sc.nextInt();
            int[][] grid = new int[m][n];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] = sc.nextInt();
                }
            }

            Solution solution = new Solution();
            System.out.println(solution.orangesRotting(grid));
        }

        sc.close();
    }
}
