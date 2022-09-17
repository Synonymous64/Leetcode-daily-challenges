#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isPalindrome(string &s){
        int i = 0, j = s.size() - 1;
        while(i < j)
            if(s[i++] != s[j--]) return false;
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int n = words.size();
        if(n < 2) return res;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; ++i){
            auto s = words[i];
            reverse(s.begin(), s.end());
            mp[s] = i;
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= words[i].size(); ++j){
                string st1 = words[i].substr(0, j); // prefix;
                string st2 = words[i].substr(j); // suffex
                if(mp.count(st1) && isPalindrome(st2) && mp[st1] != i){
                    res.push_back({i, mp[st1]});
                }
                if(!st1.empty() && mp.count(st2) && isPalindrome(st1) && mp[st2] != i){
                    res.push_back({mp[st2], i});
                }
            }
        }
        return res;
    }
    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    }
};
int main(){
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    Solution s;
    vector<vector<int>> res = s.palindromePairs(words);
    for(int i = 0; i < res.size(); ++i){
        s.printCode(res[i]);
    }
    return 0;
}