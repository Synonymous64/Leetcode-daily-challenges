#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size(), n2 = needle.size();
        if(n1 < n2) return -1;
        int i = 0, j = 0, start = 0;
        while(i < n1 && j < n2){
            if(haystack[i] == needle[j]){
                if(i - start + 1 == n2) return start;
                i++,j++;
            } else{
                j = 0;
                start++;
                i = start;
            }
        }
        return -1;
    }
};

int main(){
    string haystack = "mississippi", needle = "issip";
    Solution *s = new Solution();
    cout<<s->strStr(haystack, needle)<<endl;
    return 0;
}