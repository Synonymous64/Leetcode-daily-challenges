#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    set<vector<int>> mySet;
    void helper(vector<int> &nums, vector<int> &temp, int idx){
        if(idx == nums.size()){
            if(temp.size() > 1){
                mySet.insert(temp);
            }
            return;
        }
        int curr = nums[idx], prev = temp.size() == 0 ? -101: temp[temp.size() - 1];
        if(curr >= prev){
            temp.push_back(curr);
            helper(nums, temp, idx + 1);
            temp.pop_back();
            helper(nums, temp, idx + 1);
        } else helper(nums, temp, idx + 1);
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        helper(nums, temp, 0);
        vector<vector<int>> res(mySet.begin(), mySet.end());
        return res;
    }
};
int main(){
    vector<int> nums = {4,6,7,7};
    Solution *s = new Solution();
    vector<vector<int>> res = s->findSubsequences(nums);
    for(auto x: res)
        for(auto y: x) cout<<y<<" ";
    return 0;
}