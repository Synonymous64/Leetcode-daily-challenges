class Solution {
    private int area = 0;
    private int isValid(int[][] grid, int i, int j, int n, int m){
        if(i >= 0 && i < n && j >=0 && j < m && grid[i][j] == 1){
            grid[i][j] = 0;
            return  1 + isValid(grid, i + 1, j, n, m) + isValid(grid, i - 1, j, n, m) + isValid(grid, i, j + 1, n, m) + isValid(grid, i, j - 1, n, m);
        }
        return area;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int ans = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    ans = Math.max(ans, isValid(grid, i, j, n, m));
                }
            }
        }
        return ans;
    }
}
public class MaxAreaofIsland {
    public static void main(String[] args) {
        int[][] grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
        Solution s = new Solution();
        System.out.println(s.maxAreaOfIsland(grid));
    }
}
