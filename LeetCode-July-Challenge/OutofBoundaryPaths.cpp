#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int mod = 1e9 + 7;
    int dp[51][51][51];
    int helper(int m, int n, int maxMove, int i, int j){
        if(i >= m || i < 0 || j >= n || j < 0) return 1;
        if(maxMove <= 0) return 0;
        if(dp[maxMove][i][j] != -1) return dp[maxMove][i][j];

        long long res = 0;
        res += helper(m, n, maxMove - 1, i + 1, j);
        res += helper(m, n, maxMove - 1, i - 1, j);
        res += helper(m, n, maxMove - 1, i, j + 1);
        res += helper(m, n, maxMove - 1, i, j - 1);

        return dp[maxMove][i][j] = res % mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(m, n, maxMove, startRow, startColumn) % mod;
    }
};
int main(){
    int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
    Solution s;
    cout<<s.findPaths(m, n, maxMove, startRow, startColumn)<<endl;
    return 0;
}