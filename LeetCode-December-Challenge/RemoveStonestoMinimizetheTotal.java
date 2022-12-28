import java.util.*;
class Solution {
    private int getSum(int[] arr){
        int sum = 0;
        for(int i: arr) sum += i;
        return sum;
    }
    public int minStoneSum(int[] piles, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int x: piles) pq.add(x);
        int sum = getSum(piles);
        while(k-- != 0){
            int val = pq.poll();
            pq.add(val - val/2);
            sum -= val/2;
        }
        return sum;
    }
}
public class RemoveStonestoMinimizetheTotal {
    public static void main(String[] args) {
        int[] piles = {5,4,9}; int  k = 2;
        Solution s = new Solution();
        System.out.println(s.minStoneSum(piles, k));
    }
}
