#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int validate(vector<int> &nums, int i, int j, bool choose){
        if(i > j) return 0;
        int res = 0;
        if(choose) res = max(nums[i] + validate(nums, i + 1, j, false), nums[j] + validate(nums, i, j - 1, false));
        else res = min(-nums[i] + validate(nums, i + 1, j, true), -nums[j] + validate(nums, i, j - 1, true));
        return res;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        bool choose = true;
        int n = nums.size();
        int winScore = validate(nums, 0, n - 1, choose);
        return winScore >= 0;
    }
};

int main(){
    vector<int> nums = {1,5,233, 7};
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->PredictTheWinner(nums)<<endl;
    return 0;
}