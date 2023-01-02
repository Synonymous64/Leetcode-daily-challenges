#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long total = 0, sum = 0;
        for(auto ch: nums) total += ch;
        int mini = INT_MAX, res = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            long long backSum = total - sum;
            long long backSize = nums.size() - i - 1;
            int avg = 0;
            if(backSize == 0) avg = (sum / (i + 1));
            else avg = (abs((sum)/(i + 1) - (backSum / backSize)));
            if(mini > avg){
                mini = avg;
                res = i;
            } 
        }
        return res;
    }
};
int main(){
    vector<int> nums = {2,5,3,9,5,3};
    Solution *s = new Solution();
    cout<<s->minimumAverageDifference(nums)<<endl;
    return 0;
}