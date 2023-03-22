#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, res = 0;
        for(auto x: nums){
            if(x) count = 0;
            else count++;
            res += count;
        }
        return res;
    }
};
int main(){
    vector<int> nums = {1,3,0,0,2,0,0,4};
    Solution *s = new Solution();
    cout<<s->zeroFilledSubarray(nums)<<endl;
    return 0;
}