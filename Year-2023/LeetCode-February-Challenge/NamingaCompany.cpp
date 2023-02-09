#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string,int> mp;
        for(auto idea: ideas) mp[idea]++;

        vector<vector<int>> dp(26, vector<int>(26, 0));
        for(int i = 0; i < ideas.size(); ++i){
            string curr = ideas[i];
            char ch1 = curr[0];
            for(int j = 0; j < 26; ++j){
                char ch2 = j + 'a';
                curr[0] = ch2;
                if(mp.find(curr) == mp.end()){
                    dp[ch1 - 'a'][j]++;
                }
            }
        }
        long long res = 0;
        for(int i = 0; i < 26; ++i){
            for(int j = 0; j < 26; ++j){
                res += dp[i][j] * dp[j][i];
            }
        }
        return res;
    }
};
int main(){
    vector<string> ideas = {"coffee","donuts","time","toffee"};
    Solution *s = new Solution();
    cout<<s->distinctNames(ideas)<<endl;
    return 0;
}