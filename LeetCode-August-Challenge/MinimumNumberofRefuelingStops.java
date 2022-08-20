import java.util.*;
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int maxReach = startFuel, count = 0, index = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        while(maxReach < target){
            while(index != stations.length && stations[index][0] <= maxReach){
                pq.add(stations[index][1]);
                index++;
            }
            if(pq.isEmpty()) return -1;
            maxReach += pq.poll();
            count++;
        }
        return count;
    }
}
public class MinimumNumberofRefuelingStops {
    public static void main(String[] args) {
        int target = 100, startFuel = 1;
        int[][] stations = {{10,100}};
        Solution s = new Solution();
        System.out.println(s.minRefuelStops(target, startFuel, stations));
    }
}
