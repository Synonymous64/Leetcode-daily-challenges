#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dp[1004];
    int minCostClimbingStairsHelper(int n, vector<int>& cost) {
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];
        if(dp[n] != -1) return dp[n];
        dp[n] = cost[n] + min(minCostClimbingStairsHelper(n - 1, cost), minCostClimbingStairsHelper(n - 2, cost));
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        int ans = min(minCostClimbingStairsHelper(n - 1, cost), minCostClimbingStairsHelper(n - 2, cost));
        return ans;
    }
};
int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    Solution s;
    cout<<s.minCostClimbingStairs(cost)<<endl;
    return 0;
}