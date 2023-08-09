import java.util.*;

class Solution {
    private boolean isPair(int[] nums, int mid, int p) {
        int count = 0;
        for (int i = 0; i < nums.length - 1 && count < p; ++i) {
            if (nums[i + 1] - nums[i] <= mid) {
                count++;
                i++;
            }
        }

        return count >= p;
    }

    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int low = 0, high = nums[nums.length - 1] - nums[0];

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isPair(nums, mid, p))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
}

public class MinimizetheMaximumDifferenceofPairs {
    public static void main(String[] args) {
        int[] nums = { 10, 1, 2, 7, 1, 3 };
        int p = 2;

        System.out.println(new Solution().minimizeMax(nums, p));
    }
}