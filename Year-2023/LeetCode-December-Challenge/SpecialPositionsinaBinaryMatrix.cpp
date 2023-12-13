#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int totalRows = mat.size(), totalColumns = mat[0].size();
        vector<int> rows(totalRows, 0), cols(totalColumns, 0);

        for(int i = 0; i < totalRows; ++i){
            for(int j = 0; j < totalColumns; ++j){
                if(mat[i][j] == 1){
                    rows[i]++, cols[j]++;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < totalRows; ++i){
            for(int j = 0; j < totalColumns; ++j){
                if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) count++;
            }
        }

        return count;
    }
};

int main(){
    vector<vector<int>> mat = {{1,0,0},{0,0,1},{1,0,0}};
    Solution *s = new Solution();
    cout<<s->numSpecial(mat)<<endl;
    return 0;
}