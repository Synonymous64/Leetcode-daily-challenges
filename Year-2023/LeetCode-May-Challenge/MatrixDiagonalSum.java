class Solution {
    public int diagonalSum(int[][] mat) {
        int res = 0;
        int n = mat.length;
        for (int i = 0; i < n; ++i)
            res += mat[i][i];
        int j = n - 1;
        for (int i = 0; i < n; ++i, j--)
            if (i != j)
                res += mat[i][j];
        return res;
    }
}

public class MatrixDiagonalSum {
    public static void main(String[] args) {
        int[][] mat = { { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 } };
        System.out.println(new Solution().diagonalSum(mat));
    }
}
