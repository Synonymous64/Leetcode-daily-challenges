import java.util.*;

class Solution {
    private boolean isValid(int nr, int nc, int n) {
        return (nr >= 0 && nc >= 0 && nr < n && nc < n);
    }

    public int maxDistance(int[][] grid) {
        int n = grid.length;

        int[] dr = { 0, 0, -1, 1 };
        int[] dc = { 1, -1, 0, 0 };

        int[][] dist = new int[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dist[i][j] = -1;
            }
        }

        Queue<int[]> q = new LinkedList<>();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.add(new int[] { i, j });
                }
            }
        }

        int res = 0;
        while (!q.isEmpty()) {
            int[] vec = q.poll();
            int r = vec[0];
            int c = vec[1];

            if (grid[r][c] == 0)
                res = Math.max(res, dist[r][c]);

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (isValid(nr, nc, n) && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.add(new int[] { nr, nc });
                }
            }
        }
        return res == 0 ? -1: res;
    }
}

public class AsFarfromLandasPossible {
    public static void main(String[] args) {
        int[][] grid = {{1,0,1},{0,0,0},{1,0,1}};

        Solution s = new Solution();
        System.out.println(s.maxDistance(grid));
    }
}
