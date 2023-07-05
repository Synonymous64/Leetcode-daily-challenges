#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, end = 0, skip = 0, res = 0;

        while(end < nums.size()){
            if(nums[end] == 0) skip++;
            if(skip > 1){
                skip -= nums[start] == 0;
                start++;
            }
            res = max(res, end - start);
            end++;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,1,0,1};
    Solution *s = new Solution();
    cout<<s->longestSubarray(nums)<<endl;
    return 0;
}