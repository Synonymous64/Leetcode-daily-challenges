class Solution {
    private int kedanes(int[] nums){
        int maxSum = nums[0], currSum = nums[0];
        for(int i = 1; i < nums.length; ++i){
            if(currSum < 0) currSum = 0;
            currSum += nums[i];
            maxSum = Math.max(currSum, maxSum);
        }
        return maxSum;
    }
    public int maxSubarraySumCircular(int[] nums) {
        int x = kedanes(nums);
        int y = 0;
        for(int i = 0; i < nums.length; ++i){
            y += nums[i];
            nums[i] *= -1;
        }
        int z = kedanes(nums);
        if(y + z == 0) return x;
        return Math.max(x, y + z);
    }
}
public class MaximumSumCircularSubarray {
    public static void main(String[] args) {
        int[] nums = {5, -3 ,5}; 
        Solution s = new Solution();
        System.out.println(s.maxSubarraySumCircular(nums));
    }
}
