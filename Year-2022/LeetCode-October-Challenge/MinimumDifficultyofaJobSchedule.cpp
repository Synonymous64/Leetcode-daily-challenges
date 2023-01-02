#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> dp;
    int helper(int index, vector<int> &jobDifficulty, int d){
        int n = jobDifficulty.size();
        if(d == 1){
            int maxi = 0;
            while(index < n) maxi = max(maxi, jobDifficulty[index++]);
            return maxi;
        }
        if(dp[index][d] != -1) return dp[index][d];
        int res = INT_MAX, maxi = 0;
        for(int i = index; i < n - d + 1; ++i){
            maxi = max(maxi, jobDifficulty[i]);
            res = min(res, maxi + helper(i + 1, jobDifficulty, d - 1));
        }
        return dp[index][d] = res;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        dp.resize(jobDifficulty.size(), vector<int> (d + 1, -1));
        return helper(0, jobDifficulty, d);
    }
};
int main(){
    vector<int> jobDifficulty = {6,5,4,3,2,1};
    int d = 2;
    Solution s;
    cout<<s.minDifficulty(jobDifficulty, d)<<endl;
    return 0;
}