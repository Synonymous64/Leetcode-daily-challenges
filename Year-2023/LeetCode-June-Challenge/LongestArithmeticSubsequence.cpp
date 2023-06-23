#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(1001, 1));
        int res = 1;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = i - 1; j >= 0; --j){
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                res = max(res, dp[i][d]);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {3,6,9,12};
    Solution *s = new Solution();
    cout<<s->longestArithSeqLength(nums)<<endl;
    return 0;
}