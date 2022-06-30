#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i < k; ++i) minHeap.push(nums[i]);
        for(int i = k; i < nums.size(); ++i){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
int main(){
    Solution s;
    vector<int> nums = {1};
    int k = 1;
    cout<< s.findKthLargest(nums, k)<<endl;
    return 0;
}