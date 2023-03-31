#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
class Solution {
private:
    int helper(vector<vector<int>> &countPizza, int row, int col, int k, vector<vector<vector<int>>>&dp){
        if(k == 0){
            if(countPizza[row][col] > 0) return 1;
            return 0;
        }
        long long rows = 0, cols = 0;
        if(dp[row][col][k] != -1) return dp[row][col][k];
        for(int i = row + 1; i < countPizza.size() - 1; ++i){
            if(countPizza[i][col] >= k && countPizza[row][col] - countPizza[i][col] > 0)
                rows = (rows + helper(countPizza, i, col, k - 1, dp)) % MOD;
        }

        for(int j = col + 1; j < countPizza[0].size() - 1; ++j){
            if(countPizza[row][j] >= k && countPizza[row][col] - countPizza[row][j] > 0)
                cols = (cols + helper(countPizza, row, j, k - 1, dp)) % MOD;
        }

        return dp[row][col][k] = (rows + cols) % MOD;
    }
public:
    int ways(vector<string>& pizza, int k) {
        int row = pizza.size();
        int col = pizza[0].size();
        vector<vector<vector<int>>> dp(row + 1, vector<vector<int>>(col + 1, vector<int>(k + 1, -1)));
        vector<vector<int>> countPizza(row + 1, vector<int>(col + 1, 0));
        for(int i = row - 1; i >= 0; --i){
            for(int j = col - 1; j >= 0; --j){
                countPizza[i][j] = countPizza[i + 1][j] + countPizza[i][j + 1] - countPizza[i + 1][j + 1] + (int)(pizza[i][j] == 'A');
            }
        }

        long long res = helper(countPizza, 0, 0, k - 1, dp);
        return res;
    }
};
int main(){
    vector<string> pizza = {"A..","AAA","..."}; int k = 3;
    Solution *s = new Solution();
    cout<<s->ways(pizza, k)<<endl;
    return 0;
}