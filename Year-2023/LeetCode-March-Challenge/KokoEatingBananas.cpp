#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            long long int count = 0;
            for(int i = 0; i < piles.size(); ++i){
                if(piles[i] < mid) count++;
                else count += ((piles[i] / mid) + ((piles[i] % mid) != 0));
            }
            if(count > h) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
int main(){
    vector<int> piles = {3,6,7,11}; int h = 8;
    Solution *s = new Solution();
    cout<<s->minEatingSpeed(piles, h)<<endl;
    return 0;
}