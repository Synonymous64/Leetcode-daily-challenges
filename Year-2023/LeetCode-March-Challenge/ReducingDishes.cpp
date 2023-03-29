#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(vector<int> &satisfaction, int i, int j, vector<vector<int>> &dp){
        if(i == satisfaction.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick = j * satisfaction[i] + helper(satisfaction, i + 1, j + 1, dp);
        int notPick = helper(satisfaction, i + 1, j, dp);
        return dp[i][j] = max(pick, notPick);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return helper(satisfaction, 0, 1, dp);
    }
};
int main(){
    vector<int> satisfaction = {-1,-8,0,5,-9};
    Solution *s = new Solution();
    cout<<s->maxSatisfaction(satisfaction)<<endl;
    return 0;
}