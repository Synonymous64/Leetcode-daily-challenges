#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(auto x: nums) mp[x]++;
        for(auto x: mp) pq.push({x.second, x.first});
        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
int main(){
    vector<int> nums = {1,1,1,2,2,3}; int k = 2;
    Solution *s = new Solution();
    vector<int> res = s->topKFrequent(nums, k);
    for(auto x: res) cout<<x<<" ";
    return 0;
}