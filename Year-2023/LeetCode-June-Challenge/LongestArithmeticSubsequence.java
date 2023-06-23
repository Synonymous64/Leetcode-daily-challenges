import java.util.*;
class Solution {
    public int longestArithSeqLength(int[] nums) {
        int[][] dp = new int[nums.length][1001];
        for(int[] arr: dp)
        Arrays.fill(arr, 1);
        int res = 1;

        for(int i = 1; i < nums.length; ++i){
            for(int j = i - 1; j >= 0; --j){
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = Math.max(dp[i][d], dp[j][d] + 1);
                res = Math.max(res, dp[i][d]);
            }
        }
        return res;
    }
}
public class LongestArithmeticSubsequence{
    public static void main(String[] args) {
        int[] nums = {3,6,9,12};
        System.out.println(new Solution().longestArithSeqLength(nums));
    }
}