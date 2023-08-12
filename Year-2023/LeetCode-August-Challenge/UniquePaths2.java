class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int rows = obstacleGrid.length, cols = obstacleGrid[0].length;

        if(obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1) return 0;

        int[][] dp = new int[rows][cols];

        for(int row = 0; row < rows; ++row){
            if(obstacleGrid[row][0] == 0) dp[row][0] = 1;
            else break;
        }

        for(int col = 0; col < cols; ++col){
            if(obstacleGrid[0][col] == 0) dp[0][col] = 1;
            else break;
        }

        for(int row = 1; row < rows; ++row){
            for(int col = 1; col < cols; ++col){
                if(obstacleGrid[row][col] == 1) dp[row][col] = 0;
                else dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }

        return dp[rows - 1][cols - 1];
    }
}
public class UniquePaths2 {
    public static void main(String[] args) {
        int[][] obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
        System.out.println(new Solution().uniquePathsWithObstacles(obstacleGrid));
    }
}

