#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void mergee(vector<int> &nums, int low, int mid, int high){
        if(low >= high) return;
        int i = low, j = mid + 1, k = 0, size = high - low + 1;
        vector<int> sortIt(size, 0);
        while(i <= mid && j <= high)
            sortIt[k++] = nums[i] < nums[j] ? nums[i++]: nums[j++];
        while(i <= mid) sortIt[k++] = nums[i++];
        while(j <= high) sortIt[k++] = nums[j++];
        for(int i = 0; i < size; ++i) nums[i + low] = sortIt[i];
    }
    void mergeSort(vector<int> &nums, int low, int high){
        if(low < high){
            int mid = low + (high - low)/2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            mergee(nums, low, mid, high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main(){
    vector<int> nums = {4,3,2,1};
    Solution *s = new Solution();
    vector<int> res = s->sortArray(nums);
    for(auto ch: res) cout<<ch<<" ";
    return 0;
}