#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> mySet;
        for(auto word : words){
            string tempStr = "";
            for(auto ch : word) tempStr += morse[ch - 'a'];
            mySet.insert(tempStr);
        }
        return mySet.size();
    }
};
int main(){
    vector<string> words = {"gin","zen","gig","msg"};
    Solution s;
    cout<<s.uniqueMorseRepresentations(words)<<endl;
    return 0;
}