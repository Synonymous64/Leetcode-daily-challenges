#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    static bool sortByLength(string &word1, string &word2){
        return word1.size() < word2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), sortByLength);
        unordered_map<string, int> dp; int ans = 0;
        for(auto word : words){
            for(int i = 0; i < word.size(); ++i){
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], dp[predecessor] + 1);
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
};
int main(){
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    Solution s;
    cout<<s.longestStrChain(words)<<endl;
    return 0;
}