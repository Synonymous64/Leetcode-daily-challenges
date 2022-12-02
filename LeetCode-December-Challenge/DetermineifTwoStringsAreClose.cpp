#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26, 0), v2(26, 0), v3(26, 0), v4(26, 0);
        for(auto ch: word1) v1[ch - 'a']++, v2[ch - 'a'] = 1;
        for(auto ch: word2) v3[ch - 'a']++, v4[ch - 'a'] = 1;
        sort(v1.begin(), v1.end());
        sort(v3.begin(), v3.end());
        return v1 == v3 && v2 == v4;
    }
};
int main(){
    string word1 = "cabbba", word2 = "abbccc";
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->closeStrings(word1, word2)<<endl;
    return 0;
}