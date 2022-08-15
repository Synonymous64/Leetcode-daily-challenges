#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int values[100] = {0};
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;

        int res = 0;
        for(int i = 0; i < s.size(); ++i)
            res += values[s[i]] < values[s[i + 1]] ? -values[s[i]] : +values[s[i]]; 
        return res;
    }
};

int main(){
    string s = "MCMXCIV";
    Solution S;
    cout<<S.romanToInt(s)<<endl;
    return 0;
}