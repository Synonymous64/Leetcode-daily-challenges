import java.util.PriorityQueue;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        if(nums.length == 1) return nums[0];
        for(int i = 0; i < k; ++i) minHeap.add(nums[i]);
        for(int i = k; i < nums.length; ++i){
            if(nums[i] > minHeap.peek()){
                minHeap.remove();
                minHeap.add(nums[i]);
            }
        }
        return minHeap.peek();
    }
}
public class KthLargestElementinanArray {
    public static void main(String[] args) {
        int[] nums = {3,2,1,5,6,4};
        int k = 2;
        Solution s = new Solution();
        System.err.println(s.findKthLargest(nums, k));
    }
}
