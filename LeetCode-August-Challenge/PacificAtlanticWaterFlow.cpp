#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void helper(vector<vector<int>> &matrix, int row, int col, int prev, vector<vector<int>> &ocean){
        if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size()) return;
        if(ocean[row][col] == 1) return;
        if(prev > matrix[row][col]) return;
        ocean[row][col] = 1;
        helper(matrix, row + 1, col, matrix[row][col], ocean);
        helper(matrix, row - 1, col, matrix[row][col], ocean);
        helper(matrix, row, col + 1, matrix[row][col], ocean);
        helper(matrix, row, col - 1, matrix[row][col], ocean);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res; int rows = heights.size(), cols = heights[0].size();
        if(heights.size() < 1) return res;
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));
        for(int col = 0; col < cols; ++col){
            helper(heights, 0, col, INT_MIN, pacific);
            helper(heights, heights.size() - 1, col, INT_MIN, atlantic);
        }
        for(int row = 0; row < rows; ++row){
            helper(heights, row, 0, INT_MIN, pacific);
            helper(heights, row, heights[0].size() - 1, INT_MIN, atlantic);
        }

        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(pacific[row][col] && atlantic[row][col]){
                    vector<int> v(2);
                    v[0] = row, v[1] = col;
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};
int main(){
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution s;
    vector<vector<int>> res = s.pacificAtlantic(heights);
    for(int row = 0; row < res.size(); ++row){
        for(int col = 0; col < res[0].size(); ++col){
            cout<<res[row][col]<<" ";
        }
    }
    return 0;
}