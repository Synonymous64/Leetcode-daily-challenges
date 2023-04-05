#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = nums[0], avg = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            sum += nums[i];
            if(nums[i] > avg){
                int x = sum / (i + 1);
                if(x >= avg){
                    if(sum % (i + 1)) avg = x + 1;
                    else avg = x;
                }
            }
        }
        return avg;
    }
};
int main(){
    vector<int> nums = {13,13,20,0,8,9,9};
    Solution *s = new Solution();
    cout<<s->minimizeArrayValue(nums)<<endl;
    return 0;
}