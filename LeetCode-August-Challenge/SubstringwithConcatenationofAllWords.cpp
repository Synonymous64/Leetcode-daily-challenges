#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> count;
        for(auto word : words) count[word]++;
        vector<int> res;
        int n = s.size(), num = words.size(), len = words[0].size();
        for(int i = 0; i < (n - num * len + 1); ++i){
            unordered_map<string, int> seen;
            int j = 0;
            for(; j < num; ++j){
                string word = s.substr(i + j * len, len);
                if(count.find(word) != count.end()){
                    seen[word]++;
                    if(seen[word] > count[word]) break;
                } else break;
            }
            if(j == num) res.push_back(i);
        }
        return res;
    }
};
int main(){
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar", "foo", "the"};
    Solution S;
    vector<int> res = S.findSubstring(s, words);
    for (int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    return 0;
}