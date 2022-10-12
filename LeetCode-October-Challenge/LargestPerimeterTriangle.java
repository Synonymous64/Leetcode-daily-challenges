import java.util.Arrays;

class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        for(int i = nums.length - 1; i > 1; --i)
            if(nums[i] < nums[i - 1] + nums[i - 2])
                return nums[i] + nums[i - 1] + nums[i - 2];
        return 0;
    }
}
public class LargestPerimeterTriangle {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {2,1,2};
        System.out.println(s.largestPerimeter(nums));
    }
}
