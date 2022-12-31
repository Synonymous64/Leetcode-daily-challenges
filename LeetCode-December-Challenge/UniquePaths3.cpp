#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int res;
    void helper(vector<vector<int>> grid, int count, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return;
        if(grid[row][col] == -1 || grid[row][col] == 3) return;
        if(grid[row][col] == 2 && count == 0){
            res++;
            return;
        }
        if(grid[row][col] == 2) return;
        grid[row][col] = 3;
        helper(grid, count - 1, row + 1, col); 
        helper(grid, count - 1, row - 1, col); 
        helper(grid, count - 1, row, col + 1); 
        helper(grid, count - 1, row, col - 1); 
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = 0, col = 0, count = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    row = i;
                    col = j;
                }
                if(grid[i][j] == 0) count++;
            }
        }
        helper(grid, count + 1, row, col);
        return res;
    }
};
int main(){
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    Solution *s = new Solution();
    cout<<s->uniquePathsIII(grid)<<endl;
    return 0;
}