#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet(nums.begin(), nums.end());
        int ans = 0;
        for(auto it : nums){
            if(mySet.find(it) == mySet.end()) continue;
            int prev = it - 1, next = it + 1;
            while(mySet.find(prev) != mySet.end()) prev--;
            while(mySet.find(next) != mySet.end()) next++;
            ans = max(ans, next - prev - 1);
            mySet.erase(it);
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution s;
    cout<<s.longestConsecutive(nums)<<endl;
    return 0;
}