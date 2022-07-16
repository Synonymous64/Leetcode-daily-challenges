import java.util.Arrays;

class Solution {
    private int MOD = 1000000007;
    long[][][] dp = new long[51][51][51];
    private long helper(int m, int n, int maxMove, int i, int j){
        if(i >= m || i < 0 || j >= n || j < 0) return 1;
        if(maxMove <= 0) return 0;
        if(dp[maxMove][i][j] != -1) return dp[maxMove][i][j];
        long res = 0;
        res += helper(m, n, maxMove - 1, i + 1, j);
        res += helper(m, n, maxMove - 1, i - 1, j);
        res += helper(m, n, maxMove - 1, i, j + 1);
        res += helper(m, n, maxMove - 1, i, j - 1);

        return dp[maxMove][i][j] = res % MOD;
    }
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // Arrays.stream(dp[0]).forEach(a->Arrays.fill(a, -1));
        for(long [][] row : dp){
            for(long [] rowCols : row){
                Arrays.fill(rowCols, -1);
            }
        }
        return (int)helper(m, n, maxMove, startRow, startColumn) % MOD;
    }
}
public class OutofBoundaryPaths {
    public static void main(String[] args) {
        int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
        Solution s = new Solution();
        System.out.println(s.findPaths(m, n, maxMove, startRow, startColumn));
        
    }
}
