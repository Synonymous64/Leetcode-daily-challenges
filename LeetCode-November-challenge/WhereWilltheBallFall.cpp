#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int DFS(int row, int col, vector<vector<int>> &grid){
        if(row >= grid.size()) return col;
        if(grid[row][col] == 1 && col + 1 < grid[0].size() && grid[row][col + 1] == 1) 
            return DFS(row + 1, col + 1, grid);
        else if(grid[row][col] == -1 && col - 1 >= 0 && grid[row][col - 1] == -1)
            return DFS(row + 1, col - 1, grid);
        else return -1;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> res(cols);
        for(int col = 0; col < cols; ++col) res[col] = DFS(0, col, grid);
        return res;
    }
};
int main(){
    vector<vector<int>> grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    Solution s;
    vector<int> res = s.findBall(grid);
    for(int i = 0; i < res.size(); ++i) cout<<res[i]<<" ";
    return 0;
}