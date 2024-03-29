import java.util.*;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int rows = matrix.length, cols = matrix[0].length;
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        List<Integer> res = new ArrayList<>();
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i)
                res.add(matrix[top][i]);
            top++;
            for (int i = top; i <= bottom; ++i)
                res.add(matrix[i][right]);
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    res.add(matrix[bottom][i]);
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    res.add(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
}

public class SpiralMatrix {
    public static void main(String[] args) {
        int[][] matrix = {{1,2,3},{4,5,6},{7,8,9}};
        List<Integer> res = new Solution().spiralOrder(matrix);
        for(int x: res) System.out.print(x + " ");
    }
}