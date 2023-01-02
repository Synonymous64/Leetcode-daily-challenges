#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for(int i = 0; i < s.size(); ++i){
            res.push_back(s[i]);
            while(!res.empty() && res.back() == s[i + 1]){
                i++;
                res.pop_back();
            }
        }
        return res;
    }
};
int main(){
    string s = "abbaca";
    Solution *S = new Solution();
    cout<<S->removeDuplicates(s)<<endl;
    return 0;
}