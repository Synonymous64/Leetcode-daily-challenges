#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int res = 0;
        for(auto x: sentence){
            int ch = x - 'a';
            int bits = 1 << ch;
            res |= bits;
        }
        return res == (1 << 26) - 1;
    }
};
int main(){
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    Solution s;
    cout<<std::boolalpha<<s.checkIfPangram(sentence)<<endl;
    return 0;
}