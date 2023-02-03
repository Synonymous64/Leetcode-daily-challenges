#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int steps = (numRows - 1) * 2;
        string res = "";
        for(int i = 0; i < numRows; ++i){
            for(int j = i; j < s.size(); j+=steps){
                res+=s[j];
                if(i > 0 && i < numRows - 1 && (j + steps - 2 * i) < s.size()){
                    res += s[j + steps - 2 * i];
                }
            }
        }
        return res;
    }
};
int main(){
    string s = "PAYPALISHIRING";
    int  numRows = 4;
    Solution *S = new Solution();
    cout<<S->convert(s, numRows)<<endl;
    return 0;
}