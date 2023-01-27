#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool DFS(string &word, unordered_map<string, int> &mp, int idx){
        if(idx == word.size()) return true;
        string temp = "";
        for(int i = idx; i < word.size(); ++i){
            temp += word[i];
            if(mp[temp] > 0 && DFS(word, mp, i + 1)) return true;
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto word: words) mp[word]++;
        vector<string> res;
        for(auto word: words){
            mp[word]--;
            if(DFS(word, mp, 0)) res.push_back(word);
            mp[word]++;
        }
        return res;
    }
};
int main(){
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    Solution *s = new Solution();
    vector<string> res = s->findAllConcatenatedWordsInADict(words);
    for(auto ch: res) cout<<ch<<" ";
    cout<<endl;
    return 0;
}