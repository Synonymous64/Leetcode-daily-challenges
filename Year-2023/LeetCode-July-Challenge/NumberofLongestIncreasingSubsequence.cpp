#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        int res = 0, maxi = 1;

        for(int i = 0; i < n; ++i){
            for(int prev = 0; prev < i; ++prev){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    count[i] = count[prev];
                } else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) count[i] += count[prev];
            }
            maxi = max(maxi, dp[i]);
        }

        for(int i = 0; i < n; ++i)
            if(dp[i] == maxi)
                res += count[i];

        return res;
    }
};

int main(){
    vector<int> nums = {1,3,5,4,7};
    Solution *s = new Solution();
    cout<<s->findNumberOfLIS(nums)<<endl;
    return 0;
}