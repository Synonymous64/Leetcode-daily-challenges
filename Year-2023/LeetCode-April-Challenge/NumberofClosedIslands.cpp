#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int res = 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(visited[i][j] || grid[i][j] == 1) continue;
                queue<pair<int,int>> q ({{i, j}});
                bool isClosed = true;

                while(!q.empty()){
                    auto top = q.front();
                    q.pop();

                    for(int i = 0; i < 4; ++i){
                        int row = dx[i] + top.first;
                        int col = dy[i] + top.second;

                        if(row < 0 || row >= rows || col < 0 || col >= cols){
                            isClosed = false;
                            continue;
                        }

                        if(visited[row][col]) continue;
                        if(grid[row][col] == 1) continue;
                        visited[row][col] = true;
                        q.push({row, col});
                    }
                }
                if(isClosed) res++;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    Solution *s = new Solution();
    cout<<s->closedIsland(grid)<<endl;
    return 0;
}