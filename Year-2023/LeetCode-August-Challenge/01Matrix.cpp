#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> DIR = {0, 1, 0, -1, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        queue<pair<int,int>> q;

        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(mat[row][col] == 0) q.push({row, col});
                else mat[row][col] = -1;
            }
        }

        while(!q.empty()){
            auto ele = q.front();
            int row = ele.first, col = ele.second;
            q.pop();

            for(int i = 0; i < 4; ++i){
                int nr = row + DIR[i], nc = col + DIR[i + 1];
                if(nr < 0 || nr == rows || nc < 0 || nc == cols || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[row][col] + 1;
                q.push({nr, nc});
            }
        }

        return mat;
    }
};

int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{0,0,0}};
    Solution *s = new Solution();
    vector<vector<int>> res = s->updateMatrix(mat);

    for(auto ch: res){
        for(auto x: ch) cout<<x<<" ";
    }

    return 0;
}