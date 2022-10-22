#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(n < t.size()) return "";
        unordered_map<char, int> mp;
        for(auto &ch: t) mp[ch]++;
        int requiredCount = t.size(), minWindowSize = INT_MAX;
        int start = 0, i = 0, j = 0;
        while(j < n){
            char ch = s[j];
            if(mp[ch] > 0) requiredCount--;
            mp[ch]--;
            while(!requiredCount){
                int currWindowSize = j - i + 1;
                if(currWindowSize < minWindowSize){
                    minWindowSize = currWindowSize;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) requiredCount++;
                i++;
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start, minWindowSize);
    }
};
int main(){
    string s = "ADOBECODEBANC", t = "ABC";
    Solution S;
    cout<<S.minWindow(s, t)<<endl;
    return 0;
}