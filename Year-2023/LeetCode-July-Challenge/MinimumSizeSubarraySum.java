class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int res = Integer.MAX_VALUE, sum = 0, left = 0, right = 0;

        for (right = 0; right < nums.length; ++right) {
            sum += nums[right];
            while (sum >= target) {
                res = Math.min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return res == Integer.MAX_VALUE ? 0 : res;
    }
}

public class MinimumSizeSubarraySum {
    public static void main(String[] args) {
        int target = 7;
        int[] nums = { 2, 3, 1, 2, 4, 3 };
        System.out.println(new Solution().minSubArrayLen(target, nums));
    }
}
