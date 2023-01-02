#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        long long int val = 0;
        int i = 1;
        while(i <= n){
            val = ((val << (1 + int(log2(i)))) % MOD + i) % MOD;
            ++i;
        }
        return val;
    }
};
int main(){
    Solution s;
    cout<<s.concatenatedBinary(3)<<endl;
    return 0;
}