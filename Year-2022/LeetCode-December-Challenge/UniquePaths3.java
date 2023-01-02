class Solution {
    private int helper(int[][] grid, int count, int row, int col){
        if(row < 0 || col < 0 || row >= grid.length || col >= grid[0].length || grid[row][col] == -1) return 0 ;
        if(grid[row][col] == 2) return count == -1 ? 1: 0;
        grid[row][col] = -1;
        count--;
        int res = helper(grid, count, row + 1, col) + helper(grid, count, row - 1, col) 
        + helper(grid, count, row, col + 1) + helper(grid, count, row, col - 1);
        grid[row][col] = 0;
        count++;
        return res;
    }
    public int uniquePathsIII(int[][] grid) {
        int count = 0, row = 0, col = 0;
        for(int i = 0; i < grid.length; ++i){
            for(int j = 0; j < grid[0].length; ++j){
                if(grid[i][j] == 1){
                    row = i;
                    col = j;
                }
                if(grid[i][j] == 0) count++;
            }
        }
        return helper(grid, count, row, col);
    }
}
public class UniquePaths3 {
    public static void main(String[] args) {
        int[][] grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
        Solution s = new Solution();
        System.out.println(s.uniquePathsIII(grid));
    }
}
