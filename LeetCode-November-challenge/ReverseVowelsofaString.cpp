#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    string reverseVowels(string s) {
        int low = 0, high = s.size() - 1;
        while(low < high){
            if(isVowel(s[low]) && isVowel(s[high])){
                swap(s[low], s[high]);
                low++, high--;
            } else if(!isVowel(s[low])) low++;
            else high--;
        }
        return s;
    }
};
int main(){
    string s = "hello";
    Solution S;
    cout<<S.reverseVowels(s)<<endl;
    return 0;
}