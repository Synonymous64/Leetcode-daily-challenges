#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0}, deletions = 0;
        for(auto ch: s) freq[ch - 'a']++;

        set<int> mySet;
        for(int i = 0; i < 26; ++i){
            while(freq[i] > 0 && !mySet.insert(freq[i]).second){
                freq[i]--;
                deletions++;
            }
        }
        return deletions;
    }
};

int main(){
    string s = "ceabaacb";
    Solution *S = new Solution();
    cout<<S->minDeletions(s)<<endl;
    return 0;
}