class Solution {
    public int jump(int[] nums) {
        int current = 0, farthest = 0, jumps = 0;
        for(int i = 0; i < nums.length - 1; ++i){
            farthest = Math.max(farthest, nums[i] + i);
            if(current == i){
                jumps++;
                current = farthest;
            }
        }
        return jumps;
    }
}
public class JumpGame2{
    public static void main(String[] args) {
        int[] nums = {2,3,1,1,4};
        Solution s = new Solution();
        System.out.println(s.jump(nums));
    }
}