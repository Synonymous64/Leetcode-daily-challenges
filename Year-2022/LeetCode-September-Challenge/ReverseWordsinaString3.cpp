// class Solution {
// private:
//     void reverseStr(string &s){
//         int temp = 0;
//         int i = 0, j = s.size() - 1;
//         while(i < j){
//             // swap(s[i], s[j]);
//             temp = s[i];
//             s[i] = s[j];
//             s[j] = temp;
//             i++,j--;
//         }
//     }
// public:
//     string reverseWords(string s) {
//         string res = "";
//         for(int i = 0; i < s.size(); ++i){
//             string temp = "";
//             while(i < s.size() && s[i] != ' '){
//                 temp += s[i];
//                 i++;
//             }
//             temp += " ";
//             reverseStr(temp);
//             res += temp;
//         }
//         return res.substr(1);
//     }
// };
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0, n = s.size();
        while(left < n){
            while(right < n && s[right] != ' ') ++right;
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
            right = left;
        }
        return s;
    }
};
int main(){
    string s = "Let's take LeetCode contest";
    Solution S;
    cout<<S.reverseWords(s)<<endl;
    return 0;
}