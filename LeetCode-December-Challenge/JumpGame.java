class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length - 1;
        int lastPos = n;
        for(int i = n; i >= 0; --i)
            if(nums[i] + i >= lastPos) lastPos = i;
        return lastPos == 0;
    }
}
public class JumpGame {
    public static void main(String[] args) {
        int[] nums = {2,3,1,1,4};
        Solution s = new Solution();
        System.out.println(s.canJump(nums));
    }
}
