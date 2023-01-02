#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    bool halvesAreAlike(string s) {
        int half = 0;
        for(int i = 0; i < s.size() / 2; ++i) if(isVowel(s[i])) half++;
        for(int i = s.size() / 2; i < s.size(); ++i) if(isVowel(s[i])) half--;
        return half == 0;
    }
};
int main(){
    string s = "book";
    Solution *S = new Solution();
    cout<<std::boolalpha<<S->halvesAreAlike(s)<<endl;
    return 0;
}