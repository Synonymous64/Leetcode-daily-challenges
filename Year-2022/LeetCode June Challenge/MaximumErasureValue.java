import java.util.*;
class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length, res = 0, currSum = 0, left = 0, right = 0;
        Set<Integer> mySet = new HashSet<Integer>();
        while(right < n){
            while(mySet.contains(nums[right])){
                currSum -= nums[left];
                mySet.remove(nums[left++]);
            }
            currSum += nums[right];
            mySet.add(nums[right++]);
            res = Math.max(res, currSum);
        }
        return res;
    }
}
public class MaximumErasureValue {
    public static void main(String[] args) {
        int[] nums = {5,2,1,2,5,2,1,2,5};
        Solution s = new Solution();
        System.out.println(s.maximumUniqueSubarray(nums));
    }
}
