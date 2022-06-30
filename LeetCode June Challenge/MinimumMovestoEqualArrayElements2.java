import java.util.Arrays;

class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length, mid = nums[n/2], moves = 0;
        for(int i = 0; i < n; ++i){
            moves += Math.abs(nums[i] - mid);
        }
        return moves;
    }
}
public class MinimumMovestoEqualArrayElements2 {
    public static void main(String[] args) {
        int[] nums = {1,2,3};
        Solution s = new Solution();
        System.out.println(s.minMoves2(nums));
    }
}
