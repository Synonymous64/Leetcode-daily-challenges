#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isValid(vector<vector<int>> &grid, int i, int j, int n, int m){
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) return true;
        return false;
    }
    void DFS(vector<vector<int>> &grid, int i, int j, int n, int m, int &area){
        area++;
        grid[i][j] = 0;
        if(isValid(grid, i + 1, j, n, m)){
            DFS(grid, i + 1, j, n, m, area);
        }
        if(isValid(grid, i - 1, j, n, m)){
            DFS(grid, i - 1, j, n, m, area);
        }
        if(isValid(grid, i, j + 1, n, m)){
            DFS(grid, i, j + 1, n, m, area);
        }
        if(isValid(grid, i, j - 1, n, m)){
            DFS(grid, i, j - 1, n, m, area);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    int area = 0;
                    DFS(grid, i, j, n, m, area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int>>grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution s;
    cout<<s.maxAreaOfIsland(grid)<<endl;
    return 0;
}
