class Solution {
    private void sortingMat(int[][]mat, int row, int col, int totalRows, int totalCols){
        int[] values = new int[101];
        int r = row, c = col;
        while(r < totalRows && c < totalCols){
            values[mat[r][c]]++;
            r++;c++;
        }
        r = row; c = col;
        for(int i = 1; i < 101; ++i){
            if(values[i] > 0){
                int count = values[i];
                while(count-- > 0){
                    mat[r][c] = i;
                    r++;c++;
                }
            }
        }
    }
    public int[][] diagonalSort(int[][] mat) {
        int rows = mat.length, cols = mat[0].length;
        for(int col = 0; col < cols; ++col)
            sortingMat(mat, 0, col, rows, cols);
        for(int row = 1; row < rows; ++row)
            sortingMat(mat, row, 0, rows, cols);
        return mat;
    }
    public void printCode(int[] mat){
        for(int i = 0; i < mat.length; ++i) System.out.print(mat[i] + " ");
    }
}
public class SorttheMatrixDiagonally {
    public static void main(String[] args) {
        int[][] mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
        Solution s = new Solution();
        int[][] res = s.diagonalSort(mat);
        for(int i = 0; i < res.length; ++i){
            s.printCode(res[i]);
        }
    }
}
