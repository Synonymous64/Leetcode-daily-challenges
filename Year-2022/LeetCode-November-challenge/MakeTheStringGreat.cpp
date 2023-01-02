#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        string res;
        for(int i = 0; i < s.size(); ++i){
            res.push_back(s[i]);
            while(!res.empty() && abs(res.back() - s[i + 1]) == 32){
                res.pop_back();
                i++;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.makeGood("leEeetcode")<<endl;
    return 0;
}