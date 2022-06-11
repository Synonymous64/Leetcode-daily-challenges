class Solution {
    public int minOperations(int[] nums, int x) {
        int target = -x, res = -1, sum = 0, left = 0;
        for(int i : nums) target += i;
        if(target == 0) return nums.length;
        if(target < 0) return -1;
        for(int i = 0; i < nums.length; ++i){
            sum += nums[i];
            while(sum > target){
                sum -= nums[left++];
            }
            if(sum == target){
                res = Math.max(res, i - left + 1);
            }
        }
        return res == -1 ? -1 : nums.length - res;
    }
}
public class MinimumOperationstoReduceXtoZero {
    public static void main(String[] args) {
        int[] nums = {1,1,4,2,3};
        int x = 5;
        Solution s = new Solution();
        System.out.println(s.minOperations(nums, x));
    }
}
