import java.util.*;
class Solution {
    public int minimumDeviation(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int minValue = Integer.MAX_VALUE;

        for(int x: nums){
            if(x % 2 == 0){
                pq.add(x);
                minValue = Math.min(minValue, x);
            } else {
                pq.add(x * 2);
                minValue = Math.min(minValue, x * 2);
            }
        }

        int res = Integer.MAX_VALUE;
        while(!pq.isEmpty()){
            int top = pq.poll();
            res = Math.min(res, top - minValue);
            if(top % 2 != 0) break;
            minValue = Math.min(minValue, top / 2);
            pq.add(top / 2);
        }
        return res;
    }
}
public class MinimizeDeviationinArray{
    public static void main(String[] args) {
        int[] nums = {1,2,3,4};
        Solution s = new Solution();
        System.out.println(s.minimumDeviation(nums));
    }
}