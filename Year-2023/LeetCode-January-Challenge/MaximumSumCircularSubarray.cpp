#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int kedanes(vector<int> &nums){
        int maxSum = nums[0], currSum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(currSum < 0) currSum = 0;
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int x = kedanes(nums);
        int y = 0;
        for(auto &e: nums){
            y += e;
            e *= -1;
        }
        int z = kedanes(nums);
        if(y + z == 0) return x;
        return max(x, y + z);
    }
};
int main(){
    vector<int> nums = {5,-3,5};
    Solution *s = new Solution();
    cout<<s->maxSubarraySumCircular(nums)<<endl;
    return 0;
}