#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(auto x: nums){
            if(x <= first){
                first = x;
            } else if(x <= second){
                second = x;
            } else return true;
        }
        return false;
    }
};
int main(){
    vector<int> nums = {5,4,3,2,1};
    Solution s;
    cout<<boolalpha<<s.increasingTriplet(nums)<<endl;
    return 0;
}