#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        int len = 0, res = 0; bool flag = false;
        for(auto word: words) mp[word]++;
        for(auto x: mp){
            if(x.first[0] == x.first[1]){
                if(x.second % 2 == 1){
                    flag = true;
                    len += (x.second - 1);
                } else len += (x.second);
                mp.erase(x.first);
            } else{
                string str = x.first;
                reverse(str.begin(), str.end());
                if(mp.find(str) != mp.end()){
                    res += min(mp[str], x.second) * 4;
                }
                mp.erase(str);
                mp.erase(x.first);
            }
        }
        return flag ? res + len * 2 + 2: res + len * 2;
    }
};
int main(){
    vector<string> words = {"lc","cl","gg"};
    Solution s;
    cout<<s.longestPalindrome(words)<<endl;
    return 0;
}