import java.util.*;

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> res = new ArrayList<>();
        HashMap<Integer, Integer> mp = new HashMap<>();
        HashSet<Integer> mySet = new HashSet<>();

        for(int x: nums){
            mp.put(x, mp.getOrDefault(x, 0) + 1);
            if(mp.get(x) > nums.length / 3){
                mySet.add(x);
            }
        }

        for(int x: mySet) res.add(x);
        return res;
    }
}
public class MajorityElement2{
    public static void main(String[] args) {
        int[] nums = {3,2,3};
        List<Integer> res  = new Solution().majorityElement(nums);
        for(int x: res) System.out.println(x);
    }
}