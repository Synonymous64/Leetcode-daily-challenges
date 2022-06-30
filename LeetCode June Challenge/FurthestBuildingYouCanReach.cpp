#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxHeap;
        int sum = 0, i = 0;
        while(i < heights.size() - 1){
            if(heights[i] < heights[i + 1]){
                sum += heights[i + 1] - heights[i];
                maxHeap.push(heights[i + 1] - heights[i]);
            }
            if(sum > bricks && (ladders)){
                sum -= maxHeap.top();
                maxHeap.pop();
                --ladders;
            }
            if(sum > bricks && (!ladders)) break;
            ++i;
        }
        return i;
    }
};
int main(){
    vector<int> heights = {4,2,7,6,9,14,12};
    int bricks = 5, ladders = 1;
    Solution s;
    cout<<s.furthestBuilding(heights, bricks, ladders)<<endl;
    return 0;
}