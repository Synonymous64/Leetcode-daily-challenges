#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; ++i){
            vector<int> v(i + 1, 1);
            for(int j = 1; j < i; ++j){
                v[j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            ans.push_back(v);
        }
        return ans;
    }
    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    }
};
int main(){
    int numRows = 5;
    Solution s;
    vector<vector<int>> ans = s.generate(numRows);
    for(int i = 0; i < ans.size(); ++i){
        s.printCode(ans[i]);
    }
    return 0;
}