#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int arrIdx1 = 0, arrIdx2 = 0;
        int idx1 = 0, idx2 = 0;
        while(arrIdx1 < word1.size() && arrIdx2 < word2.size()){
            if(word1[arrIdx1][idx1] != word2[arrIdx2][idx2]) return false;
            idx1++, idx2++;
            if(idx1 == word1[arrIdx1].size()){
                idx1 = 0;
                arrIdx1++;
            }
            if(idx2 == word2[arrIdx2].size()){
                idx2 = 0;
                arrIdx2++;
            }
        }
        return arrIdx1 == word1.size() && arrIdx2 == word2.size();
    }
};
int main(){
    vector<string> word1 = {"ab", "c"}, word2 = {"a", "bc"};
    Solution s;
    cout<<std::boolalpha<<s.arrayStringsAreEqual(word1, word2)<<endl;
    return 0;
}