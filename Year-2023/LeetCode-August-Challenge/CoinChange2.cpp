#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for(auto x: coins){
            for(int i = 1; i <= amount; ++i){
                if(i - x >= 0){
                    dp[i] += dp[i - x];
                }
            }
        }
        return dp[amount];
    }
};

int main(){
    int amount = 5; vector<int> coins = {1,2,5};
    Solution *s = new Solution();
    cout<<s->change(amount, coins)<<endl;
    return 0;
}