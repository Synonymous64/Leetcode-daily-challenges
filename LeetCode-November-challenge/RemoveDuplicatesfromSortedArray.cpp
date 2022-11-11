#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[curr] != nums[i]){
                curr++;
                nums[curr] = nums[i];
            }
        }
        return curr + 1;
    }
};
int main(){
    vector<int> nums = {1,1,2};
    Solution *s = new Solution();
    cout<<s->removeDuplicates(nums)<<endl;
    return 0;
}