class Solution {
    public int numSpecial(int[][] mat) {
        int totalRows = mat.length, totalColumns = mat[0].length;
        int[] rows = new int[totalRows], cols = new int[totalColumns];

        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalColumns; ++j) {
                if (mat[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalColumns; ++j) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
}

public class SpecialPositionsinaBinaryMatrix {
    public static void main(String[] args) {
        int[][] mat = {{1,0,0},{0,0,1},{1,0,0}};
        System.out.println(new Solution().numSpecial(mat));
    }
}