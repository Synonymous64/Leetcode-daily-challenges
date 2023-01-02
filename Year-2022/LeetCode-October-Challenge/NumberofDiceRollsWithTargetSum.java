import java.util.*;

class Solution {
    private int MOD = 1000000007;
    private int helper(int dice, int faces, int target, int[][] dp){
        if(target < 0) return 0;
        if((dice == 0 && target != 0) || (dice != 0 && target == 0)) return 0;
        if(dice == 0 && target == 0) return 1;
        int res = 0;
        if(dp[dice][target] != -1) return dp[dice][target];
        for(int i = 1; i <= faces; ++i){
            res = (res + helper(dice - 1, faces, target - i, dp)) % MOD;
        }
        return ((dp[dice][target] = res) % MOD) % MOD;
    }
    public int numRollsToTarget(int n, int k, int target) {
        int[][] dp = new int[n + 1][target + 1];
        for(int[] x: dp)
            Arrays.fill(x, -1);
        return ((helper(n, k, target, dp)) % MOD) % MOD;
    }
}
public class NumberofDiceRollsWithTargetSum {
    public static void main(String[] args) {
        int n = 30, k = 30, target = 500;
        Solution s = new Solution();
        System.out.println(s.numRollsToTarget(n, k, target));
    }
}
