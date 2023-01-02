#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int counts[26] = {0};
        for(auto ch : s) counts[ch - 'a']++;
        for(int i = 0; i < s.size(); ++i)
            if(counts[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
int main(){
    Solution S;
    string s = "leetcode";
    cout<<S.firstUniqChar(s)<<endl;
    return 0;
}