class Solution {
    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rectArea1 = (ax2 - ax1) * (ay2 - ay1);
        int rectArea2 = (bx2 - bx1) * (by2 - by1);

        int x1 = Math.max(ax1, bx1);
        int x2 = Math.min(ax2, bx2);
        int y1 = Math.max(ay1, by1);
        int y2 = Math.min(ay2, by2);

        int overlapX = x2 - x1;
        int overlapY = y2 - y1;

        int commonArea = 0;
        if(overlapX > 0 && overlapY > 0){
            commonArea = overlapX * overlapY;
        }
        return rectArea1 + rectArea2 - commonArea;
    }
}
public class RectangleArea {
    public static void main(String[] args) {
        int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
        Solution s = new Solution();
        System.out.println(s.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));
    }
}
