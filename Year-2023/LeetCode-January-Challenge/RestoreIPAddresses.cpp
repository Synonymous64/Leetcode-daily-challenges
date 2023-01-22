#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void helper(string s, int start, int step, string ip, vector<string> &res){
        if(start == s.size() && step == 4){
            ip.erase(ip.end() - 1);
            res.push_back(ip);
        }

        if(s.size() - start > (4 - step) * 3) return;
        if(s.size() - start < (4 - step)) return;

        int num = 0;
        for(int i = start; i < start + 3;++i){
            num = num * 10 + (s[i] - '0');
            if(num <= 255){
                ip += s[i];
                helper(s, i + 1, step + 1, ip + '.', res);
            }
            if(num == 0) break;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        string ip = "";
        vector<string> res;
        helper(s, 0, 0, ip, res);
        return res;
    }
};
int main(){
    string s = "25525511135";
    Solution *S = new Solution();
    vector<string> res = S->restoreIpAddresses(s);
    for(auto str: res)
        for(auto ch: str) cout<<ch<<" ";
    return 0;
}