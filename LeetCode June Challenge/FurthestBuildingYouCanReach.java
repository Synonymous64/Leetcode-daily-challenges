import java.util.*;
class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int sum = 0, i = 0;
        while(i < heights.length - 1){
            if(heights[i] < heights[i + 1]){
                sum += heights[i + 1] - heights[i];
                maxHeap.add(heights[i + 1] - heights[i]); 
            }
            if(sum > bricks && ladders != 0){
                sum -= maxHeap.peek();
                maxHeap.remove(maxHeap.peek());
                --ladders;
            }
            if(sum > bricks && ladders == 0) break;
            ++i;
        }
        return i;
    }
}
public class FurthestBuildingYouCanReach {
    public static void main(String[] args) {
        int[] heights = {4,12,2,7,3,18,20,3,19};
        int bricks = 10, ladders = 2;
        Solution s = new Solution();
        System.out.println(s.furthestBuilding(heights, bricks, ladders));
    }
}
