#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenS = s.size();
        int lenP = p.size();
        if(lenP > lenS) return {};

        vector<int> pFreq(26, 0);
        vector<int> window(26, 0);

        for(int i = 0; i < lenP; ++i){
            pFreq[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        vector<int> res;
        if(pFreq == window) res.push_back(0);

        for(int i = lenP; i < lenS; ++i){
            window[s[i - lenP] - 'a']--;
            window[s[i] - 'a']++;
            if(pFreq == window) res.push_back(i - lenP + 1);
        }
        return res;
    }
};
int main(){
    string s = "cbaebabacd", p = "abc";
    Solution *S = new Solution();
    vector<int> res = S->findAnagrams(s, p);
    for(auto ch: res) cout<<ch<<" ";
    cout<<endl;
    return 0;
}