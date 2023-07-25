#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(arr[mid] < arr[mid + 1]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

int main(){
    vector<int> arr = {0,1,0};
    Solution *s = new Solution();
    cout<<s->peakIndexInMountainArray(arr)<<endl;
    return 0;
}