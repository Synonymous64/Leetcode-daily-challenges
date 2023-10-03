import java.util.*;

class Solution {
    public int numIdenticalPairs(int[] nums) {
        int res = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int x: nums) mp.put(x, mp.getOrDefault(x, 0) + 1);

        for(Map.Entry<Integer, Integer> x:  mp.entrySet()){
            int n = x.getValue();
            res += ((n) * (n - 1))/2;
        }
        return res;
    }
}
public class NumberofGoodPairs{
    public static void main(String[] args) {
        int[] nums = {1,2,3,1,1,3};
        System.out.println(new Solution().numIdenticalPairs(nums));
    }
}