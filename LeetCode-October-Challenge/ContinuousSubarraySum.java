class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        for(int i = 1; i < n; ++i)
            if(nums[i] == 0 && nums[i - 1] == 0) return true;
        for(int i = 1; i < n; ++i){
            nums[i] += nums[i - 1];
            if(nums[i] % k == 0) return true;
            int j = i;
            while(j > 1 && nums[j] > k){
                if((nums[i] - nums[j - 2]) % k == 0) return true;
                j--;
            }
        }
        return false;
    }
}
public class ContinuousSubarraySum {
    public static void main(String[] args) {
        int[] nums = {23,2,4,6,7};
        int k = 6;
        Solution s = new Solution();
        System.out.println(s.checkSubarraySum(nums, k));
    }
}
