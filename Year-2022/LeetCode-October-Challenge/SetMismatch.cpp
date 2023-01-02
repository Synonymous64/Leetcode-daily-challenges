#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(); vector<int> res(2, 0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; ++i)
            if(nums[i] == nums[i + 1]) res[0] = nums[i], nums[i] = 0;
        int sum = nums.size();
        for(int i = 0; i < n; ++i) sum ^= i ^ nums[i];
        res[1] = sum;
        return res;
    }
};
int main(){
    vector<int> nums = {1,2,2,4};
    Solution s;
    vector<int> res = s.findErrorNums(nums);
    for(int i = 0; i < res.size(); ++i) cout<<res[i]<<" ";
    return 0;
}