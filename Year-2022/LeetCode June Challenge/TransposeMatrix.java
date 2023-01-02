public class TransposeMatrix {
    public int[][] transpose(int[][] matrix) {
        int rowsSize = matrix.length, colsSize = matrix[0].length;
        int[][] myMatrix = new int[colsSize][rowsSize];
        for(int rows = 0; rows < rowsSize; ++rows){
            for(int cols = 0; cols < colsSize; ++cols){
                myMatrix[cols][rows] = matrix[rows][cols];
            }
        }  
        return myMatrix;
    }
    public static void main(String[] args) {
        
    }
}
