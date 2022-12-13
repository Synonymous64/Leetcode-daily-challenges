#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i = matrix[0].size() - 2; i >= 0; --i)
            for(int j = 0; j < matrix[0].size(); ++j)
                if(j > 0 && j < matrix[0].size() - 1) matrix[i][j] += min(matrix[i + 1][j], min(matrix[i + 1][j - 1], matrix[i + 1][j + 1]));
                else if(j == 0) matrix[i][j] += min(matrix[i + 1][j], matrix[i + 1][j + 1]);
                else matrix[i][j] += min(matrix[i + 1][j], matrix[i + 1][j - 1]);
        int res = matrix[0][0];
        for(int i = 0; i < matrix[0].size(); ++i)
            if(matrix[0][i] < res) res = matrix[0][i];
        return res;
    }
};
int main(){
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    Solution *s = new Solution();
    cout<<s->minFallingPathSum(matrix)<<endl;
    return 0;
}