#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        int i = 0;
        for(auto ch : s){
            mp[ch].push_back(i++);
        }
        int count = 0;
        for(int i = 0; i < words.size(); ++i){
            string curr = words[i];
            int latest = -1;
            for(int j = 0; j < curr.size(); ++j){
                auto it = upper_bound(mp[curr[j]].begin(), mp[curr[j]].end(), latest);
                if(it == mp[curr[j]].end()) break;
                latest = *(it);
                if(j == curr.size() - 1) count++;
            }
        }
        return count;
    }
};
int main(){
    string s = "abcde";
    vector<string> words = {"a","bb","acd","ace"};
    Solution S;
    cout<<S.numMatchingSubseq(s, words)<<endl;
    return 0;
}