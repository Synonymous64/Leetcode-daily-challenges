import java.util.*;
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> mySet = new HashSet<>();
        int ans = 0;
        for(int i : nums) mySet.add(i);
        for(int it : nums){
            if(!mySet.contains(it)) continue;
            int prev = it - 1, next = it + 1;
            while(mySet.contains(prev)) prev--;
            while(mySet.contains(next)) next++;
            ans = Math.max(ans, next - prev - 1); 
            mySet.remove(it);
        } 
        return ans;
    }
}
public class LongestConsecutiveSequence {
    public static void main(String[] args) {
        int[] nums = {0,3,7,2,5,8,4,6,0,1};
        Solution s = new Solution();
        System.out.println(s.longestConsecutive(nums));
    }
}