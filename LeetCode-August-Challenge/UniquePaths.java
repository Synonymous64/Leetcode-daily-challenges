class Solution {
    public int uniquePaths(int m, int n) {
        int[][] res = new int[m][n];
        for(int row = 0; row < m; ++row) res[row][0] = 1;
        for(int col = 0; col < n; ++col) res[0][col] = 1;
        for(int row = 1; row < m; ++row)
            for(int col = 1; col < n; ++col)
                res[row][col] = res[row - 1][col] + res[row][col - 1];
        return res[m - 1][n - 1];
    }
}
public class UniquePaths {
    public static void main(String[] args) {
        int m = 3, n = 7;
        Solution s = new Solution();
        System.out.println(s.uniquePaths(m, n));
    }
}
