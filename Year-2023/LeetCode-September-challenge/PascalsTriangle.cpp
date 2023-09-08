#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int i = 0; i < numRows; ++i){
            vector<int> temp(i + 1, 1);
            for(int j = 1; j < i; ++j){
                temp[j] = res[i - 1][j] + res[i - 1][j - 1];
            }
            res.push_back(temp);
        }
        return res;
    }

    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    }
};

int main(){
    int numRows = 5;
    Solution *s = new Solution();
    vector<vector<int>> res = s->generate(numRows);

    for(int i = 0; i < res.size(); ++i){
        s->printCode(res[i]);
    }
    return 0;
}