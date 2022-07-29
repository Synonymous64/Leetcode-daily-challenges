#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i = 0; i < words.size(); ++i){
            map<char,char> mp1;
            map<char,char> mp2;
            int flag = 1;
            for(int j = 0; j < words[i].size(); ++j){
                auto it = mp1.find(pattern[j]);
                auto it2 = mp2.find(words[i][j]);
                if(it == mp1.end()){
                    mp1.insert({pattern[j], words[i][j]});
                } else{
                    if(it->second != words[i][j]){
                        flag = 0;
                        break;
                    }
                }
                if(it2 == mp2.end()){
                    mp2.insert({words[i][j], pattern[j]});
                } else{
                    if(it2->second != pattern[j]){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag) res.push_back(words[i]);
        }
        return res;
    }
};
int main(){
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    Solution s;
    vector<string> res = s.findAndReplacePattern(words, pattern);
    for(int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    }
    return 0;
}