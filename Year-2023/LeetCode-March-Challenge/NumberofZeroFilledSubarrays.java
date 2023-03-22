class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long count = 0, res = 0;
        for (int x : nums) {
            if (x != 0)
                count = 0;
            else
                count++;
            res += count;
        }
        return res;
    }
}

public class NumberofZeroFilledSubarrays {
    public static void main(String[] args) {
        int[] nums = {1,3,0,0,2,0,0,4};
        System.out.println(new Solution().zeroFilledSubarray(nums));
    }
}