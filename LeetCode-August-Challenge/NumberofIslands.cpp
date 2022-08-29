#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void DFS(vector<vector<char>> &grid, int row, int col){
        grid[row][col] = '0';
        if(row + 1 < grid.size() && grid[row + 1][col] == '1') DFS(grid, row + 1, col);
        if(row - 1 >= 0 && grid[row - 1][col] == '1') DFS(grid, row - 1, col);
        if(col + 1 < grid[0].size() && grid[row][col + 1] == '1') DFS(grid, row, col + 1);
        if(col - 1 >= 0 && grid[row][col - 1] == '1') DFS(grid, row, col - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), count = 0;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(grid[row][col] == '1'){
                    count++;
                    DFS(grid, row, col);
                }
            }
        }
        return count;
    }
};
int main(){
    vector<vector<char>> grid= {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
        };
    Solution s;
    cout<<s.numIslands(grid)<<endl;
    return 0;
}