#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0, effectiveBuyPrice = prices[0];

        for(int i = 0; i < prices.size(); ++i){
            profit = max(profit, prices[i] - effectiveBuyPrice - fee);
            effectiveBuyPrice = min(effectiveBuyPrice, prices[i] - profit);
        }
        return profit;
    }
};

int main(){
    vector<int> prices = {1,3,2,8,4,9}; int fee = 2;
    Solution *s = new Solution();
    cout<<s->maxProfit(prices, fee)<<endl;
    return 0;
}