#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x, res = -1, sum = 0, left = 0;
        for(auto i : nums) target += i;
        if(target == 0) return nums.size();
        if(target < 0) return -1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            while(sum > target){
                sum -= nums[left++];
            }
            if(target == sum){
                res = max(res, i - left + 1);
            }
        } 
        return res == -1 ? -1 : nums.size() - res;
    }
};
int main(){
    vector<int> nums= {3,2,20,1,1,3};
    int x = 10;
    Solution s;
    cout<<s.minOperations(nums, x)<<endl;
    return 0;
}