import java.util.*;
class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points.length == 0) return 0;
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        int arrows = 1, last = points[0][1];
        for(int i = 1; i < points.length; ++i){
            if(points[i][0] > last){
                arrows++;
                last = points[i][1];
            }
        }
        return arrows;
    }
}
public class MinimumNumberofArrowstoBurstBalloons {
    public static void main(String[] args) {
        int[][] points = {{-2147483646,-2147483645},{2147483646,2147483647}};
        Solution s = new Solution();
        System.out.println(s.findMinArrowShots(points));
    }
}
