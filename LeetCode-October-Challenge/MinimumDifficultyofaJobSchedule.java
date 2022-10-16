import java.util.Arrays;

class Solution {
    private int helper(int index, int[] jobDifficulty, int d, int[][] dp){
        int n = jobDifficulty.length;
        if(d == 1){
            int maxi = 0;
            while(index < n) maxi = Math.max(maxi, jobDifficulty[index++]);
            return maxi;
        }
        if(dp[index][d] != -1) return dp[index][d];
        int res = Integer.MAX_VALUE, maxi = 0;
        for(int i = index; i < n - d + 1; ++i){
            maxi = Math.max(maxi, jobDifficulty[i]);
            res = Math.min(res, maxi + helper(i + 1, jobDifficulty, d - 1, dp));
        }
        return dp[index][d] = res;
    }
    public int minDifficulty(int[] jobDifficulty, int d) {
        if(d > jobDifficulty.length) return -1;
        int[][] dp = new int[jobDifficulty.length][d + 1];
        for(int[] x: dp)
            Arrays.fill(x, -1);
        return helper(0, jobDifficulty, d, dp);
    }
}
public class MinimumDifficultyofaJobSchedule {
    public static void main(String[] args) {
        int[] jobDifficulty = {6,5,4,3,2,1};
        int d = 2;
        Solution s = new Solution();
        System.out.println(s.minDifficulty(jobDifficulty, d));
    }
}
