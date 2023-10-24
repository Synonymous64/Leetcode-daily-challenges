#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sLen = s.size() - 1;
        int tLen = t.size() - 1;
        int sCount = 0, tCount = 0;

        while(sLen >= 0 && tLen >= 0){
            if(s[sLen] == '#'){
                sCount++;
                sLen--;
            } else if(t[tLen] == '#'){
                tCount++;
                tLen--;
            } else if(s[sLen] != '#' && sCount > 0){
                sLen--;
                sCount--;
            } else if(t[tLen] != '#' && tCount > 0){
                tLen--;
                tCount--;
            } else if(s[sLen] != t[tLen]) return false;
            else{
                sCount = 0;
                tCount = 0;
                sLen--;
                tLen--;
            }
        }

        while(sLen >= 0){
            if(s[sLen] == '#'){
                sCount++;
                sLen--;
            } else if(s[sLen] != '#' && sCount > 0){
                sCount--;
                sLen--;
            } else return false;
        }

        while(tLen >= 0){
            if(t[tLen] == '#'){
                tCount++;
                tLen--;
            } else if(t[tLen] != '#' && tCount > 0){
                tCount--;
                tLen--;
            } else return false;
        }
        return true;
    }
};

int main(){
    string s = "ab#c", t = "ad#c";
    Solution *S= new Solution();
    cout<<boolalpha<<S->backspaceCompare(s, t)<<endl;
    return 0;
}