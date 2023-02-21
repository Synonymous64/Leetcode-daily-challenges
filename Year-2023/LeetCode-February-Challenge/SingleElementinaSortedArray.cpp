#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 != 0 && nums[mid] == nums[mid - 1])) low = mid + 1;
            else high = mid;
        }
        return nums[low];
    }
};
int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    Solution *s = new Solution();
    cout<<s->singleNonDuplicate(nums)<<endl;
    return 0;
}