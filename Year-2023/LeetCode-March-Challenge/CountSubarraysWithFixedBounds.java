class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int minFound = 0, maxFound = 0, start = 0;
        long res = 0;
        boolean isMin = false, isMax = false;

        for (int i = 0; i < nums.length; ++i) {
            int num = nums[i];
            if (num < minK || num > maxK) {
                isMin = false;
                isMax = false;
                start = i + 1;
            }
            if (num == minK) {
                isMin = true;
                minFound = i;
            }
            if (num == maxK) {
                isMax = true;
                maxFound = i;
            }
            if (isMin && isMax) {
                res += (Math.min(minFound, maxFound) - start + 1);
            }
        }
        return res;
    }
}

public class CountSubarraysWithFixedBounds {
    public static void main(String[] args) {
        int[] nums = {1,3,5,2,7,5}; int minK = 1, maxK = 5;
        Solution s = new Solution();
        System.out.println(s.countSubarrays(nums, minK, maxK));
    }
}
