#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            while(size--){
                auto x = q.front();
                q.pop();
                int row = x.first;
                int col = x.second;
                for(int i = 0; i < 4; ++i){
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
                    if(newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols){
                        if(maze[newRow][newCol] == '+') continue;
                        if(newRow == 0 || newCol == 0 || newRow == rows - 1 || newCol == cols - 1) return level;
                        q.push({newRow, newCol});
                        maze[newRow][newCol] = '+';
                    }
                }
            }
        }
        return -1;
    }
};
int main(){
    vector<vector<char>> maze = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    vector<int> entrance = {1,2};
    Solution *s = new Solution();
    cout<<s->nearestExit(maze, entrance)<<endl;
    return 0;
}