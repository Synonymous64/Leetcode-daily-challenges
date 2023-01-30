#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dp[38];
    int helper(int n){
        int t1 = 0, t2 = 1;
        if(n == 0) return t1;
        if(n == 1 || n == 2) return t2;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(n - 1) + helper(n - 2) + helper(n - 3);
    }
public:
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};
int main(){
    int n = 25;
    Solution *s = new Solution();
    cout<<s->tribonacci(n)<<endl;
    return 0;
}
// class Solution {
// private:
//     int dp[38];
//     int helper(int n){
//         if(n == 0) return 0;
//         if(n == 1 || n == 2) return 1;
//         if(dp[n] != -1) return dp[n];
//         return dp[n] = helper(n - 1) + helper(n - 2) + helper(n - 3);
//     }
// public:
//     int tribonacci(int n) {
//         memset(dp, -1, sizeof(dp));
//         return helper(n);
//     }
// };