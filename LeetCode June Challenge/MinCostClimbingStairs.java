import java.util.Arrays;

class Solution {
    int[] dp = new int[1004];
    private int minCostClimbingStairsHelper(int n, int[] cost) {
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];
        if(dp[n] != -1) return dp[n];
        dp[n] = cost[n] + Math.min(minCostClimbingStairsHelper(n - 1, cost) , minCostClimbingStairsHelper(n - 2, cost));
        return dp[n];
    }
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        Arrays.fill(dp, -1);
        int ans = Math.min(minCostClimbingStairsHelper(n - 1, cost), minCostClimbingStairsHelper(n - 2, cost));
        return ans;
    }
}
public class MinCostClimbingStairs {
    public static void main(String[] args) {
        int[] cost = {1,100,1,1,1,100,1,1,100,1};
        Solution s = new Solution();
        System.out.println(s.minCostClimbingStairs(cost));
    }   
}
