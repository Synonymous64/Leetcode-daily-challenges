#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        int count = 0;
        for(int i = 0; i < 32; ++i){
            if(((n >> i) & 1) != 0){
                count++;
                if(i % 2 == 1) return false;
            }
        }
        return count == 1 ? true : false;
    }
};
int main(){
    Solution s;
    cout<<std::boolalpha<<s.isPowerOfFour(16)<<endl;
    return 0;
}