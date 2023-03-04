#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minFound = 0, maxFound = 0, start = 0; long long res = 0;
        bool isMin = false, isMax = false;

        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(num < minK || num > maxK){
                isMin = false;
                isMax = false;
                start = i + 1;
            }
            if(num == minK){
                isMin = true;
                minFound = i;
            }
            if(num == maxK){
                isMax = true;
                maxFound = i;
            }
            if(isMin && isMax){
                res += (min(minFound, maxFound) - start + 1);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,3,5,2,7,5}; int  minK = 1, maxK = 5;
    Solution *s = new Solution();
    cout<<s->countSubarrays(nums, minK, maxK)<<endl;
    return 0;
}