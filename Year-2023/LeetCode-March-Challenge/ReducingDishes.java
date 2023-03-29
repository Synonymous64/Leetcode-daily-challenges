import java.util.Arrays;

class Solution {
    private int helper(int[] satisfaction, int i, int j, int[][] dp) {
        if (i == satisfaction.length)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int pick = j * satisfaction[i] + helper(satisfaction, i + 1, j + 1, dp);
        int notPick = helper(satisfaction, i + 1, j, dp);
        return dp[i][j] = Math.max(pick, notPick);
    }

    public int maxSatisfaction(int[] satisfaction) {
        int n = satisfaction.length;
        Arrays.sort(satisfaction);
        int[][] dp = new int[n + 1][n + 1];
        for (int[] x : dp)
            Arrays.fill(x, -1);
        return helper(satisfaction, 0, 1, dp);
    }
}

public class ReducingDishes {
    public static void main(String[] args) {
        int[] satisfaction = { -1, -8, 0, 5, -9 };
        Solution s = new Solution();
        System.out.println(s.maxSatisfaction(satisfaction));
    }
}