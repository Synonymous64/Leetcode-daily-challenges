import java.util.Arrays;
class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {

        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);

        int lenH = horizontalCuts.length;
        int lenV = verticalCuts.length;

        int maxEleHor = Math.max(horizontalCuts[0] - 0, h - horizontalCuts[lenH - 1]);
        for(int i = 1; i < lenH; i++){
            int horDiff = horizontalCuts[i] - horizontalCuts[ i - 1];
            maxEleHor = Math.max(horDiff, maxEleHor);
            
        }
        int maxEleVer = Math.max(verticalCuts[0] - 0, w - verticalCuts[lenV - 1]);
        for(int i = 1; i < lenV; i++){
            int verDiff = verticalCuts[i] - verticalCuts[i - 1];
            maxEleVer = Math.max(verDiff, maxEleVer);
            
        }
        long ans = 1L * maxEleHor * maxEleVer;
        return (int) (ans % 1000000007);
    }
}
public class MaximumAreaofaPieceofCakeAfterHorizontalandVerticalCuts {
    public static void main(String[] args) {
        int h = 5, w = 4;
        int[] horizontalCuts = {3,1}, verticalCuts = {1};
        Solution s = new Solution();
        System.out.println(s.maxArea(h, w, horizontalCuts, verticalCuts));
    }
}
