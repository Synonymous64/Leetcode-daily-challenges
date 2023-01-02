#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto ch: s) mp[ch]++;
        vector<pair<char, int>> vec;
        for(auto ch: mp) vec.push_back({ch.first, ch.second});
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){return a.second > b.second;});
        string res = "";
        for(auto ch: vec)
            for(int i = 0; i < ch.second; ++i)
                res += ch.first;
        return res;
    }
};
int main(){
    string s = "tree";
    Solution *S = new Solution();
    cout<<S->frequencySort(s)<<endl;
    return 0;
}