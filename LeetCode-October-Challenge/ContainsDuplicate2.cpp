#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i){
            if(mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};
int main(){
    vector<int> nums = {1,0,1,1};
    int k = 1;
    Solution s;
    cout<<std::boolalpha<<s.containsNearbyDuplicate(nums, k)<<endl;
    return 0;
}