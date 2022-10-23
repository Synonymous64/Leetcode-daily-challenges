import java.util.Arrays;

class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length; int[] res = new int[2];
        Arrays.sort(nums);
        for(int i = 0; i < n - 1; ++i)
            if(nums[i] == nums[i + 1]){
                res[0] = nums[i];
                nums[i] = 0;
            }
        int sum = n;
        for(int i = 0; i < n; ++i) sum ^= i ^ nums[i];
        res[1] = sum;
        return res;
    }
}
public class SetMismatch {
    public static void main(String[] args) {
        int[] nums = {1,2,2,4};
        Solution s = new Solution();
        int[] res = s.findErrorNums(nums);
        for(int i = 0; i < res.length; ++i){
            System.out.print(res[i] + " ");
        }
    }
}
