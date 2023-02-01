#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if(str2.empty()) return str1;
        if(str1.substr(0, str2.size()) != str2) return "";
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};
int main(){
    string str1 = "ABCABC", str2 = "ABC";
    Solution *S = new Solution();
    cout<<S->gcdOfStrings(str1, str2)<<endl;
    return 0;
}