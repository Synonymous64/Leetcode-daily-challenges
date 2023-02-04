#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();

        if(s1Size > s2Size) return false;

        vector<int> s1Freq(26, 0);
        vector<int> window(26, 0);

        for(int i = 0; i < s1Size; ++i){
            s1Freq[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }
        if(window == s1Freq) return true;

        for(int i = s1Size; i < s2Size; ++i){
            window[s2[i - s1Size] - 'a']--;
            window[s2[i] - 'a']++;
            if(window == s1Freq) return true;
        }
        return false;
    }
};
int main(){
    string s1 = "ab", s2 = "eidbaooo";
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->checkInclusion(s1, s2)<<endl;
    return 0;
}