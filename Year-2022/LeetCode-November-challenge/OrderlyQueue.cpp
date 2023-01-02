#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1){
            string res = s;
            int n = s.size();
            string doubleString = s + s;
            for(int i = 1; i < n; ++i){
                string str = doubleString.substr(i, n);
                if(str < res){
                    res = str;
                }
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
int main(){
    string s = "cba";
    int k = 1;
    Solution S;
    cout<<S.orderlyQueue(s, k)<<endl;
    return 0;
}