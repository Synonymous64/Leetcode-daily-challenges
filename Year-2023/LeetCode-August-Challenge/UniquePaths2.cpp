#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1) return 0;

        vector<vector<int>> dp(rows, vector<int>(cols));

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
};

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution *s = new Solution();
    cout<<s->uniquePathsWithObstacles(obstacleGrid)<<endl;
    return 0;
}