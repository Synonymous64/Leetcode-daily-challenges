#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0, index = 0,  total = 0;
        for(int i = 0; i < gas.size(); ++i){
            int consume = gas[i] - cost[i];
            total += consume;
            if(total < 0){
                total = 0;
                index = i + 1;
            }
            res += consume;
        }
        return res < 0 ? -1: index;
    }
};
int main(){
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    Solution *s = new Solution();
    cout<<s->canCompleteCircuit(gas, cost)<<endl;
    return 0;
}