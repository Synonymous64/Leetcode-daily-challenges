#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int currSum = 0, count = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(auto x: nums){
            currSum = ((((x + currSum) % k) + k) % k);
            mp[currSum]++; 
            if(mp[currSum] > 1){
                count += mp[currSum] - 1;
            }
        }
        return count;
    }
};
int main(){
    vector<int> nums = {4,5,0,-2,-3,1}; int k = 5;
    Solution *s = new Solution();
    cout<<s->subarraysDivByK(nums, k)<<endl;
    return 0;
}