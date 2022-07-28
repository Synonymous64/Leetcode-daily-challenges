#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        if(lenS != lenT) return false;
        vector<int> tFreq(26, 0);
        vector<int> window(26, 0);
        for(int i = 0; i < lenT; ++i){
            tFreq[t[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        if(tFreq != window) return false;
        for(int i = lenT; i < lenS; ++i){
            window[s[i - lenT] - 'a']--;
            window[s[i] - 'a']++;
            if(tFreq != window) return false;
        }
        return true;
    }
};
int main(){
    string s = "anagram", t = "nagaram";
    Solution S;
    cout<<std::boolalpha<<S.isAnagram(s, t)<<endl;
    return 0;
}