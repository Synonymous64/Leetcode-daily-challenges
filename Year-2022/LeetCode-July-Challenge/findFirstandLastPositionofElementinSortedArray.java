class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[]{-1,-1};
        if(nums.length == 0) return res;
        int start = 0, end = nums.length - 1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] >= target) end = mid;
            else start = mid + 1;
        }
        if(nums[start] != target) return res;
        res[0] = start;
        end = nums.length;
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] > target) end = mid;
            else start = mid + 1;
        }
        res[1] = start - 1;
        return res;
    }
}
public class findFirstandLastPositionofElementinSortedArray {
    public static void main(String[] args) {
        int[] nums = {5,7,7,8,8,10};
        int target = 8;
        Solution s = new Solution();
        int[] res = s.searchRange(nums, target);
        for(int i = 0; i < res.length; ++i) System.out.print(res[i] + " ");
    }
}
