#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for(int i = 0; i < n; ++i){
            res.push_back(nums[i]);
            if(i + n < nums.size()){
                res.push_back(nums[i + n]);
            }
        }
        return res;
    }
};
int main(){
    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;
    Solution *s = new Solution();
    vector<int> res = s->shuffle(nums, n);
    for(auto ele: res) cout<<ele<<" ";
    return 0;
}