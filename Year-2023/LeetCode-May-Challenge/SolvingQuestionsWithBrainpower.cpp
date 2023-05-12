#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    long long helper(vector<vector<int>> &questions, int size, int idx, vector<long long> &dp){
        if(idx >= size) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long choose = max(questions[idx][0] + helper(questions, size, idx + questions[idx][1] + 1, dp), helper(questions, size, idx + 1, dp));
        return dp[idx] = choose;
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int size = questions.size();
        vector<long long> dp(size, -1);
        return helper(questions, size, 0, dp);
    }
};

int main(){
    vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
    Solution *s = new Solution();
    cout<<s->mostPoints(questions)<<endl;
    return 0;
}