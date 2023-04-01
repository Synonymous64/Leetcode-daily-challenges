#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if((n == 0) || (n == 1 && nums[0] != target)) return -1;
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12}; int target = 9;
    Solution *s = new Solution();
    cout<<s->search(nums, target)<<endl;
    return 0;
}