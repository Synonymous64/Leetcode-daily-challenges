#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[50];
    int fib(int n) {
        memset(dp, -1, sizeof(dp));
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
};
int main(){
    // 0 1 1 2
    Solution s;
    cout<<s.fib(3)<<endl;
    return 0;
}