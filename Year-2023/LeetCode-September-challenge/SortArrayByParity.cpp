#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(!(nums[j] & 1)){
                if(nums[i] & 1) swap(nums[i++], nums[j--]);
                else i++;
            } else j--;
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {3,1,2,4};
    Solution *s = new Solution();
    vector<int> res = s->sortArrayByParity(nums);
    for(auto x: res) cout<<x<<" ";
    return 0;
}