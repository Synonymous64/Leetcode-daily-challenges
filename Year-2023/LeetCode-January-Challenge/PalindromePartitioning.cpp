#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<string>> res;
    int dp[17][17];
    bool isPalindrome(string s, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        while(i < j){
            if(s[i] != s[j]) return dp[i][j] = false;
            i++,j--;
        }
        return dp[i][j] = true;
    }
    void helper(string s, vector<string> &temp, int idx){
        if(idx == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i = idx; i < s.size(); ++i){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i - idx + 1));
                helper(s, temp, i + 1);
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        memset(dp, -1, sizeof(dp));
        vector<string> temp;
        helper(s, temp, 0);
        return res;
    }
};
int main(){
    string s = "aab";
    Solution *S = new Solution();
    vector<vector<string>> res = S->partition(s);
    for(auto str: res)
        for(auto ch: str) cout<<ch<<" ";
    return 0;
}