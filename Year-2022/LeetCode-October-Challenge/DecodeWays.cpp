#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int>dp;
    int numWays(string s){
        int n = s.size();
        if(s[0] == '0' || n == 0) return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            if(s[i - 1] >= '1' && s[i - 1] <= '9') dp[i] = dp[i - 1];
            if(s[i - 2] == '1') dp[i] += dp[i - 2];
            else if(s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6') dp[i] += dp[i - 2];
        }
        return dp[n];
    }
public:
    int numDecodings(string s) {
        dp.resize(s.size() + 1);
        return numWays(s);
    }
};
int main(){
    string s = "10";
    Solution S;
    cout<<S.numDecodings(s)<<endl;
    return 0;
}