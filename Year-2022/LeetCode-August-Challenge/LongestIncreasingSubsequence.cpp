#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> dp;
    int helper(vector<int> &nums, int n){
        dp.resize(2504, -1);
        int res = 1;
        if(dp[n] != -1) return dp[n];
        for(int i = 0; i < n; ++i){
            if(nums[n] > nums[i])
                res = max(res, helper(nums, i) + 1);
        }
        return dp[n] = res;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; ++i){
            res = max(res, helper(nums, i));
        }
        return res;
    }
};
int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution s;
    cout<<s.lengthOfLIS(nums)<<endl;
    return 0;
}