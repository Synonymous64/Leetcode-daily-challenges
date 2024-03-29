class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length, INF = m + n;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0)
                    continue;
                int top = INF, left = INF;
                if (r - 1 >= 0)
                    top = mat[r - 1][c];
                if (c - 1 >= 0)
                    left = mat[r][c - 1];
                mat[r][c] = Math.min(top, left) + 1;
            }
        }
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (mat[r][c] == 0)
                    continue;
                int bottom = INF, right = INF;
                if (r + 1 < m)
                    bottom = mat[r + 1][c];
                if (c + 1 < n)
                    right = mat[r][c + 1];
                mat[r][c] = Math.min(mat[r][c], Math.min(bottom, right) + 1);
            }
        }
        return mat;
    }
}

public class a01Matrix {
    public static void main(String[] args) {
        int[][] mat = {{0,0,0},{0,1,0},{0,0,0}};
        Solution s = new Solution();
        int[][] res = s.updateMatrix(mat);

        for(int[] ch: res){
            for(int x: ch) System.out.print(x + " ");
        }
    }
}