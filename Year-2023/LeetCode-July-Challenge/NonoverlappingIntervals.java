import java.util.*;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        int[] prev = intervals[0];
        int res = -1;

        for (int[] x : intervals) {
            if (x[0] < prev[1] && x[1] <= prev[1]) {
                prev = x;
                res++;
            } else if (x[0] < prev[1] && x[1] > prev[1])
                res++;
            else
                prev = x;
        }

        return res;

    }
}

public class NonoverlappingIntervals {
    public static void main(String[] args) {
        int[][] intervals = {{1,2},{2,3},{3,4},{1,3}};
        System.out.println(new Solution().eraseOverlapIntervals(intervals));
    }
}