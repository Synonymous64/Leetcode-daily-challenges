import java.util.*;
class Solution {
    private int helper(int i, List<List<Integer>> piles, int k, int[][] dp){
        if(i >= piles.size() || k <= 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int res = helper(i + 1, piles, k, dp);
        int curr = 0;
        for(int idx = 0; idx < piles.get(i).size() && idx < k; ++idx){
            curr += piles.get(i).get(idx);
            res = Math.max(res, curr + helper(i + 1, piles, k - idx - 1, dp));
        }
        return dp[i][k] = res;
    }
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int[][] dp = new int[piles.size()][k + 1];
        for(int[] x: dp) Arrays.fill(x, -1);
        return helper(0, piles, k, dp);
    }
}

public class MaximumValueofKCoinsFromPiles {
    public static void main(String[] args) {
        // List<List<Integer>> piles{{1,100,3},{7,8,9}}; int k = 2;
    }
}
