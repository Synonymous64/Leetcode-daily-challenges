#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = INT_MIN;
        for(int i = 0; i < prices.size(); ++i){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution *s = new Solution();
    cout<<s->maxProfit(prices)<<endl;
    return 0;
}