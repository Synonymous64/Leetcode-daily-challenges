#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), size = max(n + 1, m + 1);
        if(n == 1 && m == 1 && nums1[0] != nums2[0]) return 0;
        int dp[size][size];
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < max(n, m); ++i){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

int main(){
    vector<int> nums1 = {1,4,2}, nums2 = {1,2,4};
    Solution *s = new Solution();
    cout<<s->maxUncrossedLines(nums1, nums2)<<endl;
    return 0;
}