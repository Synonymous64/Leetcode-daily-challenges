import java.util.*;
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length, diff = Integer.MAX_VALUE, res = 0;
        for(int i = 0; i < n; ++i){
            int first = nums[i];
            int start = i + 1;
            int end = n - 1;
            while(start < end){
                if(nums[start] + nums[end] + first == target) return target;
                else if(Math.abs(nums[start] + nums[end] + first - target) < diff){
                    diff = Math.abs(nums[start] + nums[end] + first - target);
                    res = nums[start] + nums[end] + first;
                }
                if(nums[start] + nums[end] + first < target) start++;
                else end--;
            }
        }
        return res;
    }
}
public class threeSumClosest{
    public static void main(String[] args) {
        int[] nums = {-1,2,1,-4};
        int target = 1;
        Solution s = new Solution();
        System.out.println(s.threeSumClosest(nums, target));
    }
}