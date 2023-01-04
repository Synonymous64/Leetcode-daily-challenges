import java.util.*;
class Solution {
    public int minimumRounds(int[] tasks) {
        int res = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int x: tasks) mp.put(x, mp.getOrDefault(x, 0) + 1);
        for(Map.Entry<Integer, Integer> x:  mp.entrySet()){
            if(x.getValue() <= 1) return -1;
            else if(x.getValue() == 2) res++;
            else res += (Math.ceil((double)x.getValue()/3.0));
        }
        return res;
    }
}
public class MinimumRoundstoCompleteAllTasks{
    public static void main(String[] args) {
        int[] tasks = {2,2,3,3,2,4,4,4,4,4};
        Solution s = new Solution();
        System.out.println(s.minimumRounds(tasks));
    }
}