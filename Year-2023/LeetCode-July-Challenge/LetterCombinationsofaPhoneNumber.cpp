#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void keypadPrint(int index, string digits, vector<string> &chars, string temp, vector<string> &combined){
        if(index == digits.size()){
            combined.push_back(temp);
            return;
        }

        int dig = digits[index] - '0';

        for(auto ch: chars[dig])
            keypadPrint(index + 1, digits, chars, temp + ch, combined);
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> chars = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp = "";
        vector<string> combined;
        keypadPrint(0, digits, chars, temp, combined);
        return combined;
    }
};

int main(){
    string digits = "23";
    Solution *s = new Solution();
    vector<string> res = s->letterCombinations(digits);
    for(auto ch: res)
        for(auto x: ch) cout<<x<<" ";
    return 0;
}