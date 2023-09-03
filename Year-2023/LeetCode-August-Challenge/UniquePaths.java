import java.util.*;

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];

        for (int[] x : dp)
            Arrays.fill(x, 1);

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
}

public class UniquePaths {
    public static void main(String[] args) {
        int m = 3, n = 7;
        System.out.println(new Solution().uniquePaths(m, n));
    }
}