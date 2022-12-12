import java.util.*;
class Solution {
    private int helper(int n, int[] dp){
        if(n <= 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
    public int climbStairs(int n) {
        int[] dp = new int[46];
        Arrays.fill(dp, -1);
        return helper(n, dp);
    }
}
public class ClimbingStairs {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.climbStairs(45));
    }
}
