#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int word1Len = word1.size(), word2Len = word2.size();
        int i = 0, j = 0;
        string res = "";
        while(i < word1Len && j < word2Len){
            res += word1[i++];
            res += word2[j++];
        }
        while(i < word1Len) res += word1[i++];
        while(j < word2Len) res += word2[j++];
        return res;
    }
};
int main(){
    string word1 = "ab", word2 = "pqrs";
    Solution *s = new Solution();
    cout<<s->mergeAlternately(word1, word2)<<endl;
    return 0;

}