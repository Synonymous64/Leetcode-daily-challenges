#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int i, vector<vector<int>> &piles, int k, vector<vector<int>> &dp){
        if(i >= piles.size() || k <= 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int res = helper(i + 1, piles, k, dp);
        int curr = 0;
        for(int idx = 0; idx < piles[i].size() && idx < k; ++idx){
            curr += piles[i][idx];
            res = max(res, curr + helper(i + 1, piles, k - idx - 1, dp));
        }
        return dp[i][k] = res;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(), vector<int>(k + 1, -1));
        return helper(0, piles, k, dp);
    }
};

int main(){
    vector<vector<int>> piles = {{1,100,3},{7,8,9}}; int k = 2;
    Solution *s = new Solution();
    cout<<s->maxValueOfCoins(piles, k)<<endl;
    return 0;
}