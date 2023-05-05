#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int countVowels = 0, tempCount = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') tempCount++;
            if(i - k >= 0)
                if(s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') tempCount--;
            if(tempCount > countVowels) countVowels = tempCount;
        }
        return countVowels;
    }
};

int main(){
    string s = "abciiidef"; int k = 3;
    Solution *S = new Solution();
    cout<<S->maxVowels(s, k)<<endl;
    return 0;
}