#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber){
            char ch = 'A' + (columnNumber - 1) % 26;
            res = ch + res;
            columnNumber = (columnNumber - 1) / 26;
        }
        return res;
    }
};

int main(){
    int columnNumber = 28;
    Solution *s = new Solution();
    cout<<s->convertToTitle(columnNumber)<<endl;
    return 0;
}