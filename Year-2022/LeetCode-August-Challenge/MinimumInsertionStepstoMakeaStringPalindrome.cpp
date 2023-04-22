#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        int dp[n + 1][n + 1];
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < n + 1; ++j){
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }
        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < n + 1; ++j){
                if(s[i - 1] == rev[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n - dp[n][n];
    }
};

int main(){
    string s = "zzazz";
    Solution *S = new Solution();
    cout<<S->minInsertions(s)<<endl;
    return 0;
}