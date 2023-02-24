#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minValue = INT_MAX;
        for(auto x: nums){
            if(x % 2) pq.push(x * 2), minValue = min(minValue, x * 2);
            else pq.push(x), minValue = min(minValue, x);
        }
        int res = INT_MAX;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            res = min(res, top - minValue);
            if(top % 2 != 0) break;
            minValue = min(minValue, top / 2);
            pq.push(top / 2);
        }
        return res;
    }
};
int main(){
    vector<int> nums = {1,2,3,4};
    Solution *s = new Solution();
    cout<<s->minimumDeviation(nums)<<endl;
    return 0;
}