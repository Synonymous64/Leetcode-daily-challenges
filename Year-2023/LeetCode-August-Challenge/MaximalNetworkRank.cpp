#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n, unordered_set<int> ());
        int res = 0;

        for(auto road: roads){
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int temp = adj[i].size() + adj[j].size();
                if(adj[i].count(j)) temp--;
                res = max(res, temp);
            }
        }

        return res;
    }
};

int main(){
    int n = 4; vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3}};
    Solution *s = new Solution();
    cout<<s->maximalNetworkRank(n, roads)<<endl;
    return 0;
}