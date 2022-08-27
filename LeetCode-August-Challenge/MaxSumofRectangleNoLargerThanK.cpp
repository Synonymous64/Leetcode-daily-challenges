#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN, rows = matrix.size(), cols = matrix[0].size();
        for(int l = 0; l < cols; ++l){
            vector<int> sums(rows);
            for(int j = l; j < cols; ++j){
                for(int i = 0; i < rows; ++i)
                    sums[i] += matrix[i][j];
                set<int> mySet = {0};
                int comutativeSum = 0;
                for(auto sum : sums){
                    comutativeSum += sum;
                    auto it = mySet.lower_bound(comutativeSum - k);
                    if(it != mySet.end()){
                        res = max(res, comutativeSum - *it);
                    }
                    mySet.insert(comutativeSum);
                } 
            }
        }
        return res;
    }
};
int main(){
    vector<vector<int>> matrix = {{1,0,1},{0,-2,3}};
    int k = 2;
    Solution s;
    cout<<s.maxSumSubmatrix(matrix, k)<<endl;
    return 0;
}