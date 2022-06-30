#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mid = nums[n/2], moves = 0;
        for(int i = 0; i < n; ++i)
            moves += abs(nums[i] - mid);
        return moves;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout<<s.minMoves2(nums)<<endl;
    return 0;
}