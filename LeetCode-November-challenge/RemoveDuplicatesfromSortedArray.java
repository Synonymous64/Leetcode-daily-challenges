class Solution {
    public int removeDuplicates(int[] nums) {
        int curr = 0;
        for(int i = 1; i < nums.length; ++i){
            if(nums[curr] != nums[i]){
                curr++;
                nums[curr] = nums[i];
            }
        }
        return curr + 1;
    }
}
public class RemoveDuplicatesfromSortedArray {
    public static void main(String[] args) {
        int[] nums = {0,0,1,1,1,2,2,3,3,4};
        Solution s = new Solution();
        System.out.println(s.removeDuplicates(nums));
    }
}
