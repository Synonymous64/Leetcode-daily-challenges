import java.util.*;
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        int i = 0;
        LinkedList<int[]> res = new LinkedList<>();
        while(i < n && newInterval[0] > intervals[i][1]){
            res.add(intervals[i]);
            ++i;
        }
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.add(newInterval);
        while(i < n){
            res.add(intervals[i]);
            ++i;
        }
        return res.toArray(new int[res.size()][]);
    }
}
public class InsertInterval {
    public static void main(String[] args) {
        int[][]intervals = {{1,3},{6,9}}; int[] newInterval = {2,5};
        Solution s = new Solution();
        int[][] res = s.insert(intervals, newInterval);
        for(int[] x: res){
            for(int y: x){
                System.out.print(y + " ");
            }
        }
    }
}
