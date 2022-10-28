#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); ++i){
            auto str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(strs[i]);
        }
        for(auto x: mp) res.push_back(x.second);
        return res;
    }
};
int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs);
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
    }
    return 0;
}