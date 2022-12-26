#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int lastPos = n;
        for(int i = n; i >= 0; --i)
            if(nums[i] + 1 >= lastPos) lastPos = i;
        return lastPos == 0;
    }
};

int main(){
    vector<int> nums = {2,3,1,1,4};
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->canJump(nums)<<endl;
    return 0;
}