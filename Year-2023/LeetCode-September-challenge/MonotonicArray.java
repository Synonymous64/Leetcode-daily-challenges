class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean increase = false, decrease = false;

        for(int i = 1; i < nums.length; ++i){
            if(nums[i] > nums[i - 1]) increase = true;
            else if(nums[i] < nums[i - 1]) decrease = true;
            if(increase && decrease) return false;
        }
        return true;
    }
}
public class MonotonicArray{
    public static void main(String[] args) {
        int[] nums = {1,2,2,3};
        System.out.println(new Solution().isMonotonic(nums));
    }
}