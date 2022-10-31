#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int row = 0; row < matrix.size() - 1; ++row)
            for(int col = 0; col < matrix[0].size() - 1; ++col)
                if(matrix[row][col] != matrix[row + 1][col + 1]) return false;
        return true;
    }
};
int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    Solution s;
    cout<<boolalpha<<s.isToeplitzMatrix(matrix)<<endl;
    return 0;
}