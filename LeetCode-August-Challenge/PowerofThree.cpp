#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        //! Iterative Approach 
        // while(n >= 3){
        //     if(n % 3 != 0) return false;
        //     n = n / 3;
        // }
        // return n == 1;
        //! Recursive Approach 
        if(n < 1) return false;
        if(n == 1) return true;
        if(n % 3 != 0) return false;
        return isPowerOfThree(n / 3); 
    }
};
int main(){
    Solution s;
    cout<<std::boolalpha<<s.isPowerOfThree(27)<<endl;
    return 0;
}