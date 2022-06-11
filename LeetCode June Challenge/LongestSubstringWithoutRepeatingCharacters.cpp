#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        vector<int> dict(256, -1);
        int start = -1, maxLen = 0;
        for(int i = 0; i < s.size(); ++i){
            if(dict[s[i]] > start){
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
int main(){
    string s = "pwwkew";
    Solution S;
    cout<<S.lengthOfLongestSubstring(s)<<endl;
    return 0;
}