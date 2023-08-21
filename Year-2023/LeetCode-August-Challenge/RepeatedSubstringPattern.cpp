#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s;
        for(int i = 0; i < s.size() - 1; ++i){
            temp.push_back(s[i]);
            temp.erase(0, 1);
            if(temp == s) return true;
        }
        return false;
    }
};

int main(){
    string s = "abab";
    Solution *S = new Solution();
    cout<<std::boolalpha<<S->repeatedSubstringPattern(s)<<endl;
    return 0;
}