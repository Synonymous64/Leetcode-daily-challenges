#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts) return 1.0;
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double sum = 1.0, res = 0.0;

        for(int i = 1; i <= n; ++i){
            dp[i] = sum / maxPts;
            if(i < k) sum += dp[i];
            else res += dp[i];
            if(i >= maxPts) sum -= dp[i - maxPts];
        }
        return res;
    }
};

int main(){
    int n = 10, k = 1, maxPts = 10;
    Solution *s = new Solution();
    cout<<s->new21Game(n, k, maxPts)<<endl;
    return 0;
}