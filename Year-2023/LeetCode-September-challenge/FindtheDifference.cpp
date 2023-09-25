#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char a, b;
        for(auto ch: s) a += ch;
        for(auto ch: t) b += ch;
        return b - a;
    }
};

int main(){
    string s = "abcd", t = "abcde";
    Solution *S = new Solution();
    cout<<S->findTheDifference(s, t)<<endl;
    return 0;
}