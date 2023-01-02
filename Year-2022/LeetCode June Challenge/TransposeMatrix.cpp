#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
        
    //     vector<vector<int>> res(m,vector<int> (n,0)); // matrix creation
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             res[j][i] = matrix[i][j]; // filling the matrix in transpose form
    //         }
    //     }
    //     return res;
    // }
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rowsSize = matrix.size(), colSize = matrix[0].size();
        vector<vector<int>> myMatrix(colSize, vector<int>(rowsSize, 0));
        for(int rows = 0; rows <rowsSize; ++rows){
            for(int cols = 0; cols < colSize; ++cols){
                myMatrix[cols][rows] = matrix[rows][cols];
            }
        }
        return myMatrix;
    }
    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    }
};
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    vector<vector<int>> ans = s.transpose(matrix);
    for(int i = 0; i < ans.size(); ++i){
        s.printCode(ans[i]);
    }
    return 0;
}