#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1Len = word1.size(), word2Len = word2.size();
        vector<vector<int>> dp(word1Len + 1, vector<int>(word2Len + 1, 0));
        for(int i = 1; i < word1Len + 1; ++i){
            for(int j = 1; j < word2Len + 1; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return (word1Len - dp[word1Len][word2Len]) + (word2Len - dp[word1Len][word2Len]);
    }
};
int main(){
    string word1 = "sea", word2 = "eat";
    Solution s;
    cout<<s.minDistance(word1, word2)<<endl;
    return 0;
}