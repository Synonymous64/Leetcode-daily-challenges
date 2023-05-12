import java.util.*;
class Solution {
    private long helper(int[][] questions, int size, int idx, long[] dp){
        if(idx >= size) return 0;
        if(dp[idx] != -1) return dp[idx];
        long choose = Math.max(questions[idx][0] + helper(questions, size, idx + questions[idx][1] + 1, dp), helper(questions, size, idx + 1, dp));
        return dp[idx] = choose;
    }
    public long mostPoints(int[][] questions) {
        int size = questions.length;
        long[] dp = new long[size];
        Arrays.fill(dp, -1);
        return helper(questions, size, 0, dp);
    }
}
public class SolvingQuestionsWithBrainpower{
    public static void main(String[] args) {
        int[][] questions = {{3,2},{4,3},{4,4},{2,5}};
        Solution s = new Solution();
        System.out.println(s.mostPoints(questions));
    }
}