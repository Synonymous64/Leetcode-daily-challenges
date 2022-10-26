#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i = 1; i < nums.size(); ++i)
            if(!nums[i] && !nums[i - 1]) return true;
        for(int i = 1; i < nums.size(); ++i){
            nums[i] += nums[i - 1];
            if(nums[i] % k == 0) return true;
            int j = i;
            while(j > 1 && nums[j] > k){
                if((nums[i] - nums[j - 2]) % k == 0) return true;
                j--;
            }
        }
        return false;
    }
};
int main(){
    vector<int> nums = {1,2,3};
    int k = 5;
    Solution s;
    cout<<std::boolalpha<<s.checkSubarraySum(nums, k)<<endl;
    return 0;
}