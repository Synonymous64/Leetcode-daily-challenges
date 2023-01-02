#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dp[101];
    int helper(int idx, vector<int> &nums){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = helper(idx + 2, nums) + nums[idx];
        int noTake = helper(idx + 1, nums);
        return dp[idx] = max(take, noTake);
    }
public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(0, nums);
    }
};
int main(){
    vector<int> nums = {2,1,1,2};
    Solution *s = new Solution();
    cout<<s->rob(nums)<<endl;
    return 0;
}