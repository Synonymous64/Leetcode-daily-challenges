#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        int i = 0, j = 0, n = s.size();
        while(j != n){
            if(s[j] == '*') i--;
            else s[i++] = s[j];
            j++;
        }
        return s.substr(0, i);
    }
};
int main(){
    string s = "leet**cod*e";
    Solution *S = new Solution();
    cout<<S->removeStars(s)<<endl;
    return 0;
}