#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j < i; j++)
                if ((dp[j]) && (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())) {
                    dp[i] = true;
                    break;
                }
        return dp.back();
    }
};

int main(){
    string s = "leetcode"; vector<string> wordDict = {"leet","code"};
    Solution *S = new Solution();
    cout<<std::boolalpha<<S->wordBreak(s, wordDict)<<endl;
    return 0;
}