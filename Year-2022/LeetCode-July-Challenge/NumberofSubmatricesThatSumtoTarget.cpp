#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int row = 0; row < m; ++row){
            for(int col = 1; col < n; ++col){
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        unordered_map<int,int> mp;
        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                mp = {{0, 1}};
                int sum = 0;
                for(int k = 0; k < m; ++k){
                    sum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += mp.find(sum - target) != mp.end() ? mp[sum - target] : 0;
                    mp[sum]++;
                }
            }
        }
        return res;
    }
};
int main(){
    vector<vector<int>> matrix = {{0,1,0},{1,1,1},{0,1,0}};
    int target = 0;
    Solution s;
    cout<<s.numSubmatrixSumTarget(matrix, target)<<endl;
    return 0;
}