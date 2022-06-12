#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0 , right = 0,currSum = 0, maxAns = 0;
        int res = 0;
        unordered_set<int> mySet;
        while(right < n){   
            while(mySet.find(nums[right]) != mySet.end()){
                maxAns -= nums[left], mySet.erase(nums[left++]);
            }
            maxAns += nums[right], mySet.insert(nums[right++]);
            res = max(res, maxAns);
        }
        return res;
    }
};
int main(){
    vector<int> nums = {4,2,4,5,6};
    Solution S;
    cout<<S.maximumUniqueSubarray(nums)<<endl;
    // cout<<S.maximumUniqueSubarray1(nums)<<endl;
    return 0;
}