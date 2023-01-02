#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        int start = 0, end = nums.size() - 1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] >= target) end = mid;
            else start = mid + 1;
        }
        if(nums[start] != target) return res; 
        res[0] = start;
        end = nums.size();
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] > target) end = mid;
            else start = mid + 1;
        }
        res[1] = start - 1;
        return res;
    }
};
int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution s;
    vector<int> ans = s.searchRange(nums, target);
    for(int i = 0; i < ans.size(); ++i) cout<<ans[i]<<" ";
    return 0;
}