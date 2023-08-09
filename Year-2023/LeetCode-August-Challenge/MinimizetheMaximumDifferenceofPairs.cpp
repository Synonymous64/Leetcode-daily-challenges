#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPair(vector<int> &nums, int mid, int p){
        int count = 0;
        for(int i = 0; i < nums.size() - 1 && count < p; ++i){
            if(nums[i + 1] - nums[i] <= mid){
                count++;
                i++;
            }
        }
        return count >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();

        while(low < high){
            int mid = low + (high - low)/2;
            if(isPair(nums, mid, p)) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};

int main(){
    vector<int> nums = {10,1,2,7,1,3}; int p = 2;
    Solution *s = new Solution();
    cout<<s->minimizeMax(nums, p)<<endl;
    return 0;
}