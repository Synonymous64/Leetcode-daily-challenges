#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0; vector<int> res;
        for(auto i : nums){
            if(!(i & 1)) sum += i;
        }
        for(auto x : queries){
            int index = x[1];
            int value = x[0];
            if(nums[index] % 2 == 0){
                sum -= nums[index];
            }
            nums[index] += value;
            if(nums[index] % 2 == 0){
                sum += nums[index];
            }
            res.push_back(sum);
        }
        return res;
    }
};
int main(){
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
    Solution s;
    vector<int> res = s.sumEvenAfterQueries(nums, queries);
    for(int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    }
    return 0;
}