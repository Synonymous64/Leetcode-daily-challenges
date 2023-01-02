#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq{0};
        for(int i = 1; i < nums.size(); ++i){
            if(dq.front() + k < i) dq.pop_front();
            nums[i] += nums[dq.front()];
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        return nums.back();
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,-1,-2,4,-7,3};int k = 2;
    cout<<s.maxResult(nums, k)<<endl;
    return 0;
}