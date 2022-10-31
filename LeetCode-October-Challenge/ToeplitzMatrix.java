class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for(int row = 0; row < matrix.length - 1; ++row)
            for(int col = 0; col < matrix[0].length - 1; ++col)
                if(matrix[row][col] != matrix[row + 1][col + 1]) return false;
        return true;
    }
}
public class ToeplitzMatrix {
    public static void main(String[] args) {
        int[][] matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
        Solution s = new Solution();
        System.out.println(s.isToeplitzMatrix(matrix));
    }
}
