import java.util.*;
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int row = 0; row < matrix.length; ++row){
            for(int col = 0; col < matrix[0].length; ++col){
                pq.add(matrix[row][col]);
                if(pq.size() > k){
                    pq.remove();
                }
            }
        }
        return pq.peek();
    }
}
public class KthSmallestElementinaSortedMatrix {
    public static void main(String[] args) {
        int[][] matrix = {{1,5,9},{10,11,13},{12,13,15}};
        int k = 8;
        Solution s = new Solution();
        System.out.println(s.kthSmallest(matrix, k));
    }
}
