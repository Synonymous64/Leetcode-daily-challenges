#include<bits/stdc++.h>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int rowsSize = matrix.size(), colsSize = matrix[0].size();
        sum.resize(rowsSize, vector<int>(colsSize, 0));
        for(int rows = 1; rows < rowsSize; ++rows){
            for(int cols = 0; cols < colsSize; ++cols){
                matrix[rows][cols] += matrix[rows - 1][cols];
            }
        }
        for(int rows = 0; rows < rowsSize; ++rows){
            for(int cols = 1; cols < colsSize; ++cols){
                matrix[rows][cols] += matrix[rows][cols - 1];
            }
        }
        sum = matrix;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = sum[row2][col2];
        int estra = (col1 != 0 ? sum[row2][col1 - 1] : 0) + (row1 != 0 ? sum[row1 - 1][col2] : 0) - ((row1 != 0 && col1 != 0) ? sum[row1 - 1][col1 - 1] : 0);
        return total - estra;
    }
};
int main(){
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix *numMatrix = new NumMatrix(matrix);
    cout<<numMatrix->sumRegion(2,1,4,3)<<endl;
    return 0;
}