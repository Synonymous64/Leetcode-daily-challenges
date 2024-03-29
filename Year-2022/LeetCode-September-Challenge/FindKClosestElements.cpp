#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(auto &i : arr){
            if(pq.size() >= k && abs(x - i) < pq.top().first) pq.pop();
            else if(pq.size() >= k) continue;
            pq.push({abs(x - i), i});
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 4, x = 3;
    Solution s;
    vector<int> res = s.findClosestElements(arr, k, x);
    for(int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    } cout<<endl;
    return 0;
}