class Solution {
    public int minimumAverageDifference(int[] nums) {
        long total = 0, sum = 0;
        for(int ch: nums) total += ch;
        long mini = Integer.MAX_VALUE, res = 0;
        for(int i = 0; i < nums.length; ++i){
            sum += nums[i];
            long backSum = total - sum;
            long backSize = nums.length - i - 1;
            long avg = 0;
            if(backSize == 0) avg = (sum / (i + 1));
            else avg = (Math.abs(sum / (i + 1) - (backSum / backSize)));
            if(mini > avg){
                mini = avg;
                res = i;
            }
        }
        return (int)res;
    }
}
public class MinimumAverageDifference {
    public static void main(String[] args) {
        int[] nums = {2,5,3,9,5,3};
        Solution s = new Solution();
        System.out.println(s.minimumAverageDifference(nums));
    }
}
