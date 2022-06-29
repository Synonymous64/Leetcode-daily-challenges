import java.util.*;
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (a, b)->a[0] ==  b[0] ? a[1] - b[1] : b[0] - a[0]);
        List<int[]> ans = new ArrayList<>();
        for(int[] p : people){
            ans.add(p[1], p);
        }
        return ans.toArray(new int[ans.size()][]);
    }
    void printCode(int[] ans){
        for(int i = 0; i < ans.length; ++i){
            System.out.print(ans[i] + " ");
        }
    }
}
public class QueueReconstructionbyHeight {
    public static void main(String[] args) {
        int[][] people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
        Solution s = new Solution();
        int[][] ans = s.reconstructQueue(people);
        for(int i = 0; i < ans.length; ++i){
            s.printCode(ans[i]);
        }
    }
}
