class Solution {
    private int validate(int[] nums, int i, int j, boolean choose) {
        if (i > j)
            return 0;
        int res = 0;
        if (choose)
            res = Math.max(nums[i] + validate(nums, i + 1, j, false), nums[j] + validate(nums, i, j - 1, false));
        else
            res = Math.min(-nums[i] + validate(nums, i + 1, j, true), -nums[j] + validate(nums, i, j - 1, true));
        return res;
    }

    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        boolean choose = true;
        int maxScore = validate(nums, 0, n - 1, choose);
        return maxScore >= 0;
    }
}

public class PredicttheWinner {
    public static void main(String[] args) {
        int[] nums = { 1, 5, 233, 7 };
        System.out.println(new Solution().PredictTheWinner(nums));
    }
}