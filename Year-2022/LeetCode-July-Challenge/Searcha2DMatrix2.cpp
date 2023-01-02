#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = m - 1, j = 0; i >= 0 && j < n;){
            if(target == matrix[i][j]) return true;
            else if(target > matrix[i][j])j++;
            else i--;
        }
        return false;
    }
};
int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    Solution s;
    cout<<std::boolalpha<<s.searchMatrix(matrix, target)<<endl;
    return 0;
}