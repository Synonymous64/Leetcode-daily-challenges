#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1){
            int firstTop = pq.top();
            pq.pop();
            int secondTop = pq.top();
            pq.pop();
            if(firstTop == secondTop) continue;
            else pq.push(firstTop - secondTop);
        }
        return pq.size() ? pq.top(): 0;
    }
};

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    Solution *s = new Solution();
    cout<<s->lastStoneWeight(stones)<<endl;
    return 0;
}