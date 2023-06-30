#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isPossible(int row, int col, int mid, vector<vector<int>> &cells){
        vector<vector<int>> grid(row + 1, vector<int>(col + 1, 0));
        vector<pair<int,int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < mid; ++i)
            grid[cells[i][0]][cells[i][1]] = 1;

        queue<pair<int,int>> q;

        for(int i = 1; i <= col; ++i){
            if(grid[1][i] == 0){
                q.push({1, i});
                grid[1][i] = 1;
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int r = p.first, c = p.second;
            for(auto d: directions){
                int nr = r + d.first, nc = c + d.second;
                if(nr > 0 && nc > 0 && nr <= row && nc <= col && grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    if(nr == row) return true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = row * col, latestDay = 0;
        while(low < high - 1){
            int mid = low + (high - low)/2;
            if(isPossible(row, col, mid, cells)){
                low = mid;
                latestDay = mid;
            } else high = mid;
        }
        return latestDay;
    }
};

int main(){
    vector<vector<int>> cells = {{1,1},{2,1},{1,2},{2,2}};
    int row = 2, col = 2;
    Solution *s = new Solution();
    cout<<s->latestDayToCross(row, col, cells)<<endl;
    return 0;
}