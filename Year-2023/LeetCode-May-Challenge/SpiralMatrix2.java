class Solution {
    public int[][] generateMatrix(int n) {
        int startRow = 0, endRow = n - 1;
        int startCol = 0, endCol = n - 1;
        int total = n * n, counter = 1;
        int[][] res = new int[n][n];
        while (counter <= total) {
            for (int i = startCol; i <= endCol && counter <= total; ++i)
                res[startRow][i] = counter++;
            startRow++;
            for (int i = startRow; i <= endRow && counter <= total; ++i)
                res[i][endCol] = counter++;
            endCol--;
            for (int i = endCol; i >= startCol && counter <= total; --i)
                res[endRow][i] = counter++;
            endRow--;
            for (int i = endRow; i >= startRow && counter <= total; --i)
                res[i][startCol] = counter++;
            startCol++;
        }
        return res;
    }
}

public class SpiralMatrix2 {
    public static void main(String[] args) {
        int n = 3;
        int[][] res = new Solution().generateMatrix(n);
        for(int[] arr: res)
            for(int x: arr) System.out.print(x + " ");
    }
}