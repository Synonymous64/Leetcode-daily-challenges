class Solution {
    public int minFallingPathSum(int[][] matrix) {
        for(int i = matrix.length - 2; i >= 0; --i)
            for(int j = 0; j < matrix[0].length; ++j)
                if(j > 0 && j < matrix[0].length - 1) matrix[i][j] += Math.min(matrix[i + 1][j], Math.min(matrix[i + 1][j - 1], matrix[i + 1][j + 1]));
                else if(j == 0) matrix[i][j] += Math.min(matrix[i + 1][j], matrix[i + 1][j + 1]);
                else matrix[i][j] += Math.min(matrix[i + 1][j], matrix[i + 1][j - 1]);
            int res = matrix[0][0];
            for(int i = 0; i < matrix[0].length; ++i)
                if(matrix[0][i] < res) res = matrix[0][i];
            return res;

    }
}
public class MinimumFallingPathSum{
    public static void main(String[] args) {
        int[][] matrix = {{2,1,3},{6,5,4},{7,8,9}};
        Solution s = new Solution();
        System.out.println(s.minFallingPathSum(matrix));
    }
}
