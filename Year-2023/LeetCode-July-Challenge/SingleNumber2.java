import java.util.*;

class Solution {
    public int singleNumber(int[] nums) {
        if (nums.length < 3)
            return nums[0];

        Arrays.sort(nums);

        if (nums[0] != nums[1])
            return nums[0];

        for (int i = 1; i < nums.length - 1; ++i)
            if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
                return nums[i];

        return nums[nums.length - 1];

    }
}

public class SingleNumber2 {
    public static void main(String[] args) {
        int[] nums = { 0, 1, 0, 1, 0, 1, 99 };
        System.out.println(new Solution().singleNumber(nums));
    }
}