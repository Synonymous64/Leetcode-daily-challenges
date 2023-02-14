#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0; string res = "";

        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            carry = sum > 1 ? 1: 0;
            res += to_string(sum % 2);
        }
        if(carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
int main(){
    string a = "11", b = "1";
    Solution *s = new Solution();
    cout<<s->addBinary(a, b)<<endl;
    return 0;
}