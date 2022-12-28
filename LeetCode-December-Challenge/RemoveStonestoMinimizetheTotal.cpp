#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int res = accumulate(piles.begin(), piles.end(), 0);
        while(k--){
            int val = pq.top();
            pq.pop();
            pq.push(val - val/2);
            res -= val/2;
        }
        return res;
    }
};
int main(){
    vector<int> piles = {5,4,9}; int k = 2;
    Solution *s = new Solution();
    cout<<s->minStoneSum(piles, k)<<endl;
    return 0;
}