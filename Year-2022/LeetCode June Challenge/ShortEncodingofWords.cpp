#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> mySet(words.begin(), words.end());
        for(auto ch : words){
            int size = ch.size();
            for(int i = 1; i < size; ++i){
                string str = ch.substr(i, size);
                if(mySet.find(str) != mySet.end()){
                    mySet.erase(str);
                }
            }
        }
        int ans = 0;
        for(auto myWords : mySet){
            ans += myWords.size() + 1;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<string> words = {""};
    cout<<s.minimumLengthEncoding(words)<<endl;
    return 0;

}