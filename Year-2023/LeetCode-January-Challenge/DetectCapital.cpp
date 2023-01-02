#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isUpper = true, isLower = true;
        if(word.size() <= 1) return true;
        for(int i = 1; i < word.size(); ++i){
            if(isupper(word[i])) isLower = false;
            if(islower(word[i])) isUpper = false;
        }
        return isLower ||(isUpper && isupper(word[0]));
    }
};
int main(){
    Solution *s = new Solution();
    string word = "ggg";
    cout<<std::boolalpha<<s->detectCapitalUse(word)<<endl;
    return 0;
}