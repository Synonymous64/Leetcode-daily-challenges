#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<char,int> mp;
    bool helper(string &s1, string &s2){
        int s1Size = s1.size(), s2Size = s2.size();
        int minSize = min(s1Size, s2Size);
        for(int i = 0; i < minSize; ++i){
            if(mp[s1[i]] < mp[s2[i]]) return true;
            else if(mp[s1[i]] > mp[s2[i]]) return false;
        }
        return s2Size >= s1Size;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); ++i) mp[order[i]] = i;
        int n = words.size();
        for(int i = 0; i < n - 1; ++i){
            if(!helper(words[i], words[i + 1])) return false;
        }
        return true;
    }
};
int main(){
    vector<string> words = {"hello","leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->isAlienSorted(words, order)<<endl;
    return 0;
}