#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dp[101][21][101];
    int minCostHelper(int i, int l, int t, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        if(t > target) return INT_MAX/2;
        if(i == m){
            return (t == target) ? 0 : INT_MAX/2;
        }
        if(dp[i][l][t] != -1) return dp[i][l][t];
        else {
            int ans = INT_MAX/2;
            if(houses[i] == 0){
                for(int j = 0; j < n; ++j){
                    ans = min(ans, cost[i][j] + minCostHelper(i + 1, j + 1,(l == j + 1) ? t : t + 1, houses, cost, m, n, target));
                }
            } else {
                ans = min(ans,  minCostHelper(i + 1, houses[i], (houses[i] == l) ? t : t + 1, houses,cost, m, n, target));
            }
            return dp[i][l][t] = ans;
        }
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = minCostHelper(0, 0, 0, houses, cost, m, n, target);
        return ans == INT_MAX/2 ? -1 : ans;
    }
};
int main(){
    vector<int> houses =  {3,1,2,3};
    vector<vector<int>> cost = {{1,1,1},{1,1,1},{1,1,1},{1,1,1}};
    int m = 4;
    int n = 3;
    int target = 3;
    Solution s;
    cout<<s.minCost(houses, cost, m, n, target)<<endl;
    return 0;
}