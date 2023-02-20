class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
}
public class SearchInsertPosition{
    public static void main(String[] args) {
        int[] nums = {1,3,5,6}; int target = 5;
        Solution s = new Solution();
        System.out.println(s.searchInsert(nums, target));
    }
}