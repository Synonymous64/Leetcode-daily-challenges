#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, current = 0, farthest = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            farthest = max(farthest, nums[i] + i);
            if(current == i){
                jumps++;
                current = farthest;
            }
        }
        return jumps;
    }
};
int main(){
    vector<int> nums = {2,3,1,1,4};
    Solution *S = new Solution();
    cout<<S->jump(nums)<<endl;
    return 0;
}