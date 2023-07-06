#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, left = 0, right = 0, sum = 0;
        for(right = 0; right < nums.size(); ++right){
            sum += nums[right];
            while(sum >= target){
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0: res;
    }
};

int main(){
    int target = 7; vector<int> nums = {2,3,1,2,4,3};
    Solution *s = new Solution();
    cout<<s->minSubArrayLen(target, nums)<<endl;
    return 0;
}