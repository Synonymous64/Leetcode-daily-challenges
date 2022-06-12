#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, maxLen = 0, currSum = 0;
        unordered_set<int> mySet;
        while(right < n){
            while(mySet.find(nums[right]) != mySet.end())
                currSum -= nums[left], mySet.erase(nums[left++]);
            currSum += nums[right], mySet.insert(nums[right++]);
            maxLen = max(maxLen, currSum);
        }
        return maxLen;
    }
};
int main(){
    vector<int> nums = {5,2,1,2,5,2,1,2,5};
    Solution S;
    cout<<S.maximumUniqueSubarray(nums)<<endl;
    // cout<<S.maximumUniqueSubarray1(nums)<<endl;
    return 0;
}