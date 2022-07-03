class Solution {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length, maxLen = 0;
        if(n == 1) return 1;
        int prevDiff = nums[1] - nums[0];
        maxLen = prevDiff == 0 ? 1 : 2;
        for(int i = 2; i < n; ++i){
            int currDiff = nums[i] - nums[i - 1];
            if((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0)){
                maxLen++;
                prevDiff = currDiff;
            }
        }        
        return maxLen;
    }
}                                                                                                   
public class WiggleSubsequence {
    public static void main(String[] args) {
        int[] nums = {1,7,4,9,2,5};
        Solution s = new Solution();
        System.out.println(s.wiggleMaxLength(nums));
    }
}
