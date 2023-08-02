#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void combination(vector<int> &nums, vector<vector<int>> &res, int low, int high){
        if(low == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = low; i <= high; ++i){
            swap(nums[i], nums[low]);
            combination(nums,  res, low + 1, high);
            swap(nums[i], nums[low]);
        }

        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        combination(nums, res, 0, nums.size() - 1);
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution *s = new Solution();
    vector<vector<int>> res = s->permute(nums);
    for(auto x: res)
        for(auto ch: x) cout<<ch<<" ";
    return 0;
}