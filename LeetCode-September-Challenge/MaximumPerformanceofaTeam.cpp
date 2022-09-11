#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int MOD = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> vec;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; ++i) vec.push_back({efficiency[i], speed[i]});
        sort(vec.begin(), vec.end());
        long sum = 0, res = 0;
        for(int i = n - 1; i >= 0; --i){
            sum += vec[i].second;
            pq.push(vec[i].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, sum * vec[i].first);
        }
        return res % MOD;
    }
};
int main(){
    int n = 6, k = 2;
    vector<int> speed = {2,10,3,1,5,8}, efficiency = {5,4,3,9,7,2};
    Solution s;
    cout<<s.maxPerformance(n, speed, efficiency, k)<<endl;
    return 0;
}