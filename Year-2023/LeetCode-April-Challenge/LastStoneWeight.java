import java.util.*;
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int x: stones) pq.add(x);
        while(pq.size() > 1){
            int firstTop = pq.poll();
            int secondTop = pq.poll();
            if(firstTop == secondTop) continue;
            else pq.add(firstTop - secondTop);
        }
        return pq.size() != 0 ? pq.peek(): 0;
    }
}
public class LastStoneWeight {
    public static void main(String[] args) {
        int[] stones = {2,7,4,1,8,1};
        System.out.println(new Solution().lastStoneWeight(stones));
    }
}
