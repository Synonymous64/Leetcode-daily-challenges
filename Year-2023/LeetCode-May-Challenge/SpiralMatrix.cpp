#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        vector<int> res;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; ++i)
                res.push_back(matrix[top][i]);
            top++;
            for(int i = top; i <= bottom; ++i)
                res.push_back(matrix[i][right]);
            right--;
            if(top <= bottom){
                for(int i = right; i >= left; --i)
                    res.push_back(matrix[bottom][i]);
                bottom--;
            }
            if(left <= right){
                for(int i = bottom;i >= top; --i)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution *s = new Solution();
    vector<int> res = s->spiralOrder(matrix);
    for(auto x: res) cout<<x<<" ";
    return 0;
}