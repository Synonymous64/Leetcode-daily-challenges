#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int countUnique = 0;
        for(auto ch: s){
            if(!mp[ch]){
                mp[ch]++;
            }else{
                countUnique++;
                mp.clear();
                mp[ch]++;
            }
        }
        return ++countUnique;
    }
};
int main(){
    string s = "abacaba";
    Solution *S = new Solution();
    cout<<S->partitionString(s)<<endl;
    return 0;
}