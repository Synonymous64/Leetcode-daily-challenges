class Solution {
    private int DFS(int row, int col, int[][] grid){
        if(row >= grid.length) return col;
        if(grid[row][col] == 1 && col + 1 < grid[0].length && grid[row][col + 1] == 1) 
            return DFS(row + 1, col + 1, grid);
        else if(grid[row][col] == -1 && col - 1 >= 0 && grid[row][col - 1] == -1)
            return DFS(row + 1, col - 1, grid);
        else return -1;
    }
    public int[] findBall(int[][] grid) {
        int cols = grid[0].length;
        int[] res = new int[cols];
        for(int col = 0; col < cols; ++ col) res[col] = DFS(0, col, grid);
        return res;
    }
}
public class WhereWilltheBallFall {
    public static void main(String[] args) {
        int[][] grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
        Solution s = new Solution();
        int[] res = s.findBall(grid);
        for(int i = 0; i < res.length; ++i) System.out.print(res[i] + " ");
    }
}
