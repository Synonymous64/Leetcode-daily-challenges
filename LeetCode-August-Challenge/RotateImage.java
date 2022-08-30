class Solution {
    public void rotate(int[][] matrix) {
        int rows = matrix.length;
        for(int row = 0; row < rows; ++row){
            for(int col = row; col < rows; ++col){
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < rows/2; ++col){
                int temp = matrix[row][col];
                matrix[row][col] = matrix[row][rows - col - 1];
                matrix[row][rows - col - 1] = temp;
            }
        }
    }
    public void printCode(int[] matrix){
        for(int i = 0; i < matrix.length; ++i){
            System.out.print(matrix[i] + " ");
        }
        System.out.println();
    }
}
public class RotateImage {
    public static void main(String[] args) {
        int[][] matrix = {{1,2,3},{4,5,6},{7,8,9}};
        Solution s = new Solution();
        s.rotate(matrix);
        for(int i = 0; i < matrix.length; ++i){
            s.printCode(matrix[i]);
        }
    }
}
