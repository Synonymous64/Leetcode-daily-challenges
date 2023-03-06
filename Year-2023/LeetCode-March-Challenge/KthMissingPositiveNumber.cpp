#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size();
        while(low < high){
            int mid = low + (high - low)/2;
            if(arr[mid] - mid > k) high = mid;
            else low = mid + 1;
        }
        return high + k;
    }
};
int main(){
    vector<int> arr = {2,3,4,7,11}; int k = 5;
    Solution *s = new Solution();
    cout<<s->findKthPositive(arr, k)<<endl;
    return 0;
}