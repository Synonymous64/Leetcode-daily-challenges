#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int pos = -1;
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] > nums[i + 1]){
                if(pos != -1) return false;
                pos = i;
            }
        }
        return (pos == -1 || pos == 0 || pos == nums.size() - 2 || nums[pos - 1] <= nums[pos + 1] || nums[pos] <= nums[pos + 2]);
    }
};
int main(){
    vector<int> nums = {4,2,3};
    Solution s;
    cout<<::boolalpha<<s.checkPossibility(nums)<<endl;
    return 0;
}