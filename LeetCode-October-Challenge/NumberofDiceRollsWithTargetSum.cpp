#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MOD = 1e9+7;
    int helper(int dice, int faces, int target, vector<vector<int>> &dp){
        if(target < 0) return 0;
        if((!dice && target) || (dice && !target)) return 0;
        if(!dice && !target) return 1;
        int res = 0;
        if(dp[dice][target] != -1)  return dp[dice][target];
        for(int i = 1; i <= faces; ++i){
            res = (res + helper(dice - 1, faces, target - i, dp)) % MOD;
        }
        return (dp[dice][target] = res) % MOD;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
        return helper(n, k, target, dp);
    }
};
int main(){
    int n = 30, k = 30, target = 500;
    Solution s;
    cout<<s.numRollsToTarget(n, k, target)<<endl;
    return 0;
}