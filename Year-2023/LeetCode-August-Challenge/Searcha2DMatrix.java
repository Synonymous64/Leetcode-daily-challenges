class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length, cols = matrix[0].length;
        for(int i = row - 1, j = 0; i >= 0 && j < cols;){
            if(target == matrix[i][j]) return true;
            else if(target > matrix[i][j]) j++;
            else i--;
        }
        return false;
    }
}
public class Searcha2DMatrix{
    public static void main(String[] args) {
        int[][] matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
        int target = 5;
        System.out.println(new Solution().searchMatrix(matrix, target));
    }
}