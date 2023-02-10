#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isValid(int nr, int nc, int n){
        return (nr >= 0 && nc >= 0 && nr < n && nc < n);
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<vector<int>> q;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int res = 0;
        while(!q.empty()){
            vector<int> vec = q.front();
            q.pop();
            int r = vec[0];
            int c = vec[1];

            if(grid[r][c] == 0) res = max(res, dist[r][c]);

            for(int i = 0; i < 4; ++i){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(isValid(nr, nc, n) && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return res == 0 ? -1: res;
    }
};
int main(){
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    Solution *s = new Solution();
    cout<<s->maxDistance(grid)<<endl;
}