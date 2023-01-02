import java.util.*;
class Solution {
    private int[] dp;
    private int helper(int idx, int[] nums){
        if(idx >= nums.length) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = helper(idx + 2, nums) + nums[idx];
        int noTake = helper(idx + 1, nums);
        return dp[idx] = Math.max(take, noTake);
    }
    public int rob(int[] nums) {
        dp = new int[101];
        Arrays.fill(dp, -1);
        return helper(0, nums);
    }
}
public class HouseRobber{
    public static void main(String[] args) {
        int[] nums = {2,1,1,2};
        Solution s = new Solution();
        System.out.println(s.rob(nums));
    }
}