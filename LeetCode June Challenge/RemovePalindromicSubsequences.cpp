#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        int n = s.size(), i = 0, j = n - 1;
        while(i <= j){
            if(s[i] != s[j]) return 2;
            else i++; --j;
        }
        return 1;
    }
};
int main(){
    Solution s;
    cout<<s.removePalindromeSub("baabb")<<endl;
    return 0;
}