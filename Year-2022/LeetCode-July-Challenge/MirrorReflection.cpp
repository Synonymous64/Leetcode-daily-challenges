//* Ext * p = reflec * q 
//* If ext = even and ref = odd, result is 0 
//* If ext = odd and ref = even, result is 2 
//* If ext = odd and ref = odd, result is 1 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int extension = q, reflection = p;
        while(extension % 2 == 0 && reflection % 2 == 0){
            extension /= 2;
            reflection /= 2;
        }
        if(extension % 2 == 0 && reflection % 2 != 0) return 0;
        if(extension % 2 != 0 && reflection % 2 == 0) return 2;
        if(extension % 2 != 0 && reflection % 2 != 0) return 1;
        return -1;
    }
};
int main(){
    int p = 2, q = 1;
    Solution s;
    cout<<s.mirrorReflection(p, q)<<endl;
    return 0;
}