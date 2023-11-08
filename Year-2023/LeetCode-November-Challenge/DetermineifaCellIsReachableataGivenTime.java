
class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xDiff = Math.abs(fx - sx), yDiff = Math.abs(fy - sy);
        if(xDiff == 0 && yDiff == 0 && t == 1) return false;
        return Math.min(xDiff, yDiff) + Math.abs(xDiff - yDiff) <= t;
    }
}

public class DetermineifaCellIsReachableataGivenTime{
    public static void main(String[] args) {
        int sx = 2, sy = 4, fx = 7, fy = 7, t = 6;
        Solution s = new Solution();
        System.out.println(s.isReachableAtTime(sx, sy, fx, fy, t));
    }
}
