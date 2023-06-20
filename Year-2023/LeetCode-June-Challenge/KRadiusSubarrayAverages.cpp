#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        int n = nums.size();
        vector<int> averages(n, -1);

        if(2 * k + 1 > n) return averages;
        long long windowSum = 0;

        for(int i = 0; i < (2 * k + 1); ++i)
            windowSum += nums[i];
        averages[k] = windowSum / (2 * k + 1);

        for(int i = (k * 2 + 1); i < n; ++i){
            int deductElement = nums[i - (2 * k + 1)];
            int insertElement = nums[i];
            windowSum = windowSum - deductElement + insertElement;
            averages[i - k] = windowSum / (2 * k + 1);
        }
        return averages;
    }
};

int main(){
    vector<int> nums = {7,4,3,9,1,8,5,2,6}; int k = 3;
    Solution *s = new Solution();
    vector<int> res = s->getAverages(nums, k);
    for(auto x: res) cout<<x<<" ";
    return 0;
}