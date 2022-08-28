#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void sortingMat(vector<vector<int>> &mat, int row, int col, int totalRows, int totalCols){
        int values[101] = {0}, r = row, c = col;
        while(r < totalRows && c < totalCols){
            values[mat[r][c]]++;
            r++,c++;
        }
        r = row, c = col;
        for(int i = 1; i < 101; ++i){
            if(values[i]){
                int count = values[i];
                while(count--){
                    mat[r][c] = i;
                    r++,c++;
                }
            }
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        for(int col = 0; col < cols; ++col)
            sortingMat(mat, 0, col, rows, cols);
        for(int row = 1; row < rows; ++row)
            sortingMat(mat, row, 0, rows, cols);
        return mat;
    }
    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    }
};
int main(){
    vector<vector<int>>mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    Solution s;
    vector<vector<int>> res = s.diagonalSort(mat);
    for(int i = 0; i < res.size(); ++i)
        s.printCode(res[i]);
    return 0;
}