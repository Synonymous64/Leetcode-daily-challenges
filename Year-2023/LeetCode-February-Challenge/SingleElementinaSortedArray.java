class Solution {
    public int singleNonDuplicate(int[] nums) {
        int low = 0, high = nums.length - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 != 0 && nums[mid] == nums[mid - 1])) low = mid + 1;
            else high = mid;
        }
        return nums[low];
    }
}
public class SingleElementinaSortedArray{
    public static void main(String[] args) {
        int[] nums = {1,1,2,3,3,4,4,8,8};
        Solution s = new Solution();
        System.out.println(s.singleNonDuplicate(nums));
    }
}