import java.util.*;
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int currSum = 0, count = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1);
        for(int x: nums){
            currSum = ((((x + currSum) % k ) + k) % k);
            mp.put(currSum, mp.getOrDefault(currSum, 0) + 1);
            if(mp.get(currSum) > 1){
                count += mp.get(currSum) - 1;
            }
        }
        return count;
    }
}
public class SubarraySumsDivisiblebyK {
    public static void main(String[] args) {
        int[] nums = {4,5,0,-2,-3,1}; int k = 5;
        Solution s = new Solution();
        System.out.println(s.subarraysDivByK(nums, k));
    }
}
