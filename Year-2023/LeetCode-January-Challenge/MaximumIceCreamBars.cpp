#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        if(costs[0] > coins) return 0;
        int count = 0;
        for(int i = 0; i < costs.size(); ++i){
            if(costs[i] <= coins){
                count++;
                coins -= costs[i];
            } else count;
        }
        return count;
    }
};
int main(){
    vector<int> costs = {10,6,8,7,7,8}; int coins = 5;
    Solution *s = new Solution();
    cout<<s->maxIceCream(costs, coins)<<endl;
    return 0;
}