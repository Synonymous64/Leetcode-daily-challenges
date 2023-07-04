#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() < 3) return nums[0];

        sort(nums.begin(), nums.end());
        if(nums[0] != nums[1]) return nums[0];

        for(int i = 1; i < nums.size() - 1; ++i)
            if(nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
                return nums[i];

        return nums[nums.size() - 1];
    }
};

int main(){
    vector<int>  nums = {0,1,0,1,0,1,99};
    Solution *s = new Solution();
    cout<<s->singleNumber(nums)<<endl;
    return 0;
}