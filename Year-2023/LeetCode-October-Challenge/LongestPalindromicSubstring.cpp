#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0, n = s.size(), maxLen = 0;
        if(n <= 1) return s;
        for(int i = 0; i < n - 1; ++i){
            int left = i, right = i;
            while(left >= 0 && right < n){
                if(s[left] == s[right]){
                    --left; ++right;
                } else break;
            }
            int len = right - left - 1;
            if(maxLen < len){
                maxLen = len;
                start = left + 1;
                end = right - 1;
            }
        }
        for(int i = 0; i < n - 1; ++i){
            int left = i, right = i + 1;
            while(left >= 0 && right < n){
                if(s[left] == s[right]){
                    --left; ++right;
                } else break;
            }
            int len = right - left - 1;
            if(maxLen < len){
                maxLen = len;
                start = left + 1;
                end = right - 1;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main(){
    Solution *S = new Solution();
    string s = "cbbd";

    cout<<S->longestPalindrome(s)<<endl;
    return 0;
}