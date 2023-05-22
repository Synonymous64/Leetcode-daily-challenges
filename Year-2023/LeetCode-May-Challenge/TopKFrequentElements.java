import java.util.*;
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
        for(int x: nums) mp.put(x, mp.getOrDefault(x, 0) + 1);
        for(Map.Entry<Integer, Integer> x: mp.entrySet()){
            pq.add(x);
        }
        int[] res = new int[k];
        while(k-- != 0){
            res[k] = pq.poll().getKey();
        }
        return res;
    }
}
public class TopKFrequentElements{
    public static void main(String[] args) {
        int[] nums = {1,1,1,2,2,3}; int k = 2;
        int[] res = new Solution().topKFrequent(nums, k);
        for(int x: res) System.out.print(x + " ");
    }
}