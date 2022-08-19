import java.util.*;
class Solution {
    public boolean isPossible(int[] nums) {
        HashMap<Integer, Integer> m = new HashMap<>();
        HashMap<Integer, Integer> m1 = new HashMap<>();
        for(int i : nums) m.put(i, m.getOrDefault(i, 0) + 1);
        for(int i : nums){
            if(m.get(i) <= 0) continue;
            m.put(i, m.getOrDefault(i, 0) - 1);
            if(m1.getOrDefault(i - 1, 0) > 0){
                m1.put(i - 1, m1.getOrDefault(i - 1, 0) - 1);
                m1.put(i, m1.getOrDefault(i, 0) + 1);
            } else if(m.getOrDefault(i + 1, 0) > 0 && m.getOrDefault(i + 2, 0) > 0){
                m.put(i + 1, m.getOrDefault(i + 1, 0) - 1);
                m.put(i + 2, m.getOrDefault(i + 2, 0) - 1);
                m1.put(i + 2, m1.getOrDefault(i + 2, 0) + 1);
            } else return false;
        }
        return true;
    }
}
public class SplitArrayintoConsecutiveSubsequences {
    public static void main(String[] args) {
        int[] nums =  {1,2,3,4,4,5};
        Solution s = new Solution();
        System.out.println(s.isPossible(nums));
    }
}
