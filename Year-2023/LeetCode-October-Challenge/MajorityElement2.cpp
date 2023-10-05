#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        set<int> mySet;
        vector<int> res;

        for(auto x: nums){
            if(++mp[x] > nums.size() / 3){
                mySet.insert(x);
            }
        }

        for(auto x: mySet) res.push_back(x);
        return res;
    }
};

int main(){
    vector<int> nums = {3,2,3};
    Solution *s = new Solution();
    vector<int> res = s->majorityElement(nums);
    for(auto x: res) cout<<x<<endl;
    return 0;
}