#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, res = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            int first = nums[i];
            int start = i + 1;
            int end = n - 1;
            while(start < end){
                if(nums[start] + nums[end] + first == target) return target;
                else if(abs(nums[start] + nums[end] + first - target) < diff){
                    diff = abs(nums[start] + nums[end] + first - target);
                    res = nums[start] + nums[end] + first;
                }
                if(nums[start] + nums[end] + first < target) start++;
                else end--;
            }
        }
        return res;
    }
};
int main(){
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution s;
    cout<<s.threeSumClosest(nums, target)<<endl;
    return 0;
}