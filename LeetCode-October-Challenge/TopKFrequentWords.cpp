#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    class camp{
    public:
        bool operator()(pair<int, string> &a, pair<int, string> &b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto str: words) mp[str]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, camp> pq;
        for(auto x: mp){
            if(pq.size() < k){
                pq.push({x.second, x.first});
            } else{
                if(pq.top().first < x.second){
                    pq.pop();
                    pq.push({x.second, x.first});
                } else if(pq.top().first == x.second && pq.top().second > x.first){
                    pq.pop();
                    pq.push({x.second, x.first});
                }
            }
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main(){
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    Solution s;
    vector<string> res = s.topKFrequent(words, k);
    for(int i = 0; i < res.size(); ++i) cout<<res[i]<<" ";
    return 0;
}