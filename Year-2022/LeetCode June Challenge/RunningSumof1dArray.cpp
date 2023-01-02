#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.empty()) return {};
        for(int i = 1; i < nums.size(); ++i){
            nums[i] += nums[i - 1];
        }
        return nums;
    }
    void displayCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    }
};
int main(){
    vector<int> nums = {3,1,2,10,1};
    Solution s;
    vector<int> ans = s.runningSum(nums);
    s.displayCode(ans);
    return 0;
    
}