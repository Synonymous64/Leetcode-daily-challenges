#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        for(int i = 0; i < mat.size(); ++i) res += mat[i][i];
        int j = mat.size() - 1;
        for(int i = 0; i < mat.size(); ++i, j--)
        if(i != j) res += mat[i][j];
        return res;
    }
};
int main(){
    vector<vector<int>> mat = {{1,2,3},
                            {4,5,6},
                            {7,8,9}};
    Solution *s = new Solution();
    cout<<s->diagonalSum(mat)<<endl;
    return 0;
}