import java.util.*;

class Solution {
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int mod = 1000000007;
        int n = nums.length, low = 0, high = n - 1;
        int[] pow = new int[n];
        Arrays.fill(pow, 1);
        for (int i = 1; i < n; ++i) {
            pow[i] = (pow[i - 1] * 2) % mod;
        }
        int res = 0;
        while (low <= high) {
            if (nums[low] + nums[high] > target)
                high--;
            else {
                res = (res + pow[high - low]) % mod;
                low++;
            }
        }
        return res % mod;
    }
}

public class NumberofSubsequencesThatSatisfytheGivenSumCondition {
    public static void main(String[] args) {
        int[] nums = {14,4,6,6,20,8,5,6,8,12,6,10,14,9,17,16,9,7,14,11,14,15,13,11,10,18,13,17,17,14,17,7,9,5,10,13,8,5,18,20,7,5,5,15,19,14}; int target = 22;
        System.out.println(new Solution().numSubseq(nums, target));
    }
}