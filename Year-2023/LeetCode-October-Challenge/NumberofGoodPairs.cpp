#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for(auto &x: nums) mp[x]++;

        for(auto &x: mp){
            int n = x.second;
            res += ((n) * (n - 1))/2;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3,1,1,3};
    Solution *s = new Solution();
    cout<<s->numIdenticalPairs(nums)<<endl;
    return 0;
}