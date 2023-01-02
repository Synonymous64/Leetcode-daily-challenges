#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), maxLen = 0;
        if(n == 1) return 1;          
        int prevDiff = nums[1] - nums[0];
        prevDiff == 0 ? maxLen = 1 : maxLen = 2;
        for(int i = 2; i < n; ++i){
            int currDiff = nums[i] - nums[i - 1];
            if((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0)){
                maxLen++;
                prevDiff = currDiff;
            }
        }
        return maxLen;
    }
};
int main(){
    vector<int> nums = {1,7,4,9,2,5};
    Solution s;
    cout<<s.wiggleMaxLength(nums)<<endl;
    return 0;
}