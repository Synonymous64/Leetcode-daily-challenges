#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isValid(vector<int> &weights, int days, int capacity){
        int requiredDays = 1;
        int currWeights = 0;
        for(auto x: weights){
            if(currWeights + x > capacity){
                currWeights = 0;
                requiredDays++;
            }
            currWeights += x;
        }
        if(requiredDays > days) return false;
        else return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for(auto x: weights){
            low = max(low, x);
            high += x;
        }
        int res = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isValid(weights, days, mid)){
                res = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return res;
    }
};
int main(){
    vector<int> weights = {3,2,2,4,1,4}; int days = 3;
    Solution *s = new Solution();
    cout<<s->shipWithinDays(weights, days)<<endl;
    return 0;
}