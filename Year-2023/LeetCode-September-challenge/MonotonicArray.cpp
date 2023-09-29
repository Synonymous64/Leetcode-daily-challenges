#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase = false, decrease = false;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i - 1]) increase = true;
            else if(nums[i] < nums[i - 1]) decrease = true;
            if(increase && decrease) return false;
        }
        return true;
    }
};

int main(){
    vector<int> nums = {1,2,2,3};
    Solution *s = new Solution();
    cout<<boolalpha<<s->isMonotonic(nums)<<endl;
    return 0;
}