#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < row; ++col){
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
        for(int i = 0; i < rows; ++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    void printCode(vector<int> &matrix){
        for(int i = 0; i < matrix.size(); ++i) cout<<matrix[i]<<" ";
        cout<<endl;
    }
};
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(matrix);
    for(int i = 0; i < matrix.size(); ++i){
        s.printCode(matrix[i]);
    }
    return 0;
}
