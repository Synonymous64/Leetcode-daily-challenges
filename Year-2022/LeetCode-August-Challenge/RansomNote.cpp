#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for(auto i : magazine) count[i - 'a']++;
        for(auto i : ransomNote) 
            if(count[i - 'a']-- <= 0) return false;
        return true;
    }
};
int main(){
    Solution s;
    string ransomNote = "a", magazine = "b";
    cout<<std::boolalpha<<s.canConstruct(ransomNote, magazine)<<endl;
    return 0;
}