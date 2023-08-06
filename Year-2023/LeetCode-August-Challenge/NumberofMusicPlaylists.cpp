#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;
    long long helper(int n, int goal, int k, vector<vector<long long>> &dp){
        if(n == 0 && goal == 0) return 1;
        if(n == 0 || goal == 0) return 0;
        if(dp[n][goal] != -1) return dp[n][goal];

        long long playOld = helper(n, goal - 1, k, dp) * (max(0, n - k));
        long long playNew = helper(n - 1, goal - 1, k, dp) * n;

        return dp[n][goal] = (playOld + playNew) % MOD;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1, -1));
        return helper(n, goal, k, dp);
    }
};

int main(){
    int n = 3, goal = 3, k = 1;
    Solution *s = new Solution();
    cout<<s->numMusicPlaylists(n, goal, k)<<endl;
    return 0;
}