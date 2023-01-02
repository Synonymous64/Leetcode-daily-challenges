class Solution {
    public int lengthOfLIS(int[] arr) {
        int amax = 1;
        int[]dp = new int[arr.length];
        for(int i=0; i<arr.length; i++){
            int max = 0;
            for(int j=0; j<i; j++){
                if(arr[j] < arr[i]) max = Math.max(max, dp[j]);
            }
            dp[i] = max+1;
            amax = Math.max(amax, dp[i]);
        }    
        return amax;
    }
}
public class LongestIncreasingSubsequence {
    public static void main(String[] args) {
        int[] nums = {10,9,2,5,3,7,101,18};
        Solution s = new Solution();
        System.out.println(s.lengthOfLIS(nums));
        
    }
}
