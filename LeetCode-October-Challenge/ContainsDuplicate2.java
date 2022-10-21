import java.util.*;
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> mp = new TreeMap<>();
        for(int i = 0; i < nums.length; ++i){
            if(mp.containsKey(nums[i]) && i  -  mp.get(nums[i]) <= k) return true;
            mp.put(nums[i], i);
        }
        return false;
    }
}
public class ContainsDuplicate2 {
    public static void main(String[] args) {
        int[] nums = {1,0,1,1};
        int k = 1;
        Solution s = new Solution();
        System.out.println(s.containsNearbyDuplicate(nums, k));
    }
}
