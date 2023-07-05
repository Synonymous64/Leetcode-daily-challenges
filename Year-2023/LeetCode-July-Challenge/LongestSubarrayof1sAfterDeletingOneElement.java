class Solution {
    public int longestSubarray(int[] nums) {
        int start = 0, end = 0, res = 0, skip = 0;

        while(end < nums.length){
            if(nums[end] == 0) skip++;
            if(skip > 1){
                if(nums[start] == 0) skip--;
                start++;
            }
            res = Math.max(res, end - start);
            end++;
        }
        return res;
    }
}
public class LongestSubarrayof1sAfterDeletingOneElement{
    public static void main(String[] args) {
        int[] nums = {1,1,0,1};
        System.out.println(new Solution().longestSubarray(nums));
    }
}