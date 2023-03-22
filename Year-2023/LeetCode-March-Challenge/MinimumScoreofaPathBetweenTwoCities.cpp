#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<bool> visited;
    void DFS(vector<vector<pair<int,int>>> &adj, int node, int &res){
        if(visited[node]) return;
        visited[node] = true;
        for(auto &x: adj[node]){
            res = min(res, x.second);
            DFS(adj, x.first, res);
        }
        return;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        visited.resize(n + 1, false);
        for(auto edge: roads){
            int u = edge[0];
            int v = edge[1];
            int dist = edge[2];
            adj[u].emplace_back(v, dist);
            adj[v].emplace_back(u, dist);
        }
        int res = 1e5;
        DFS(adj, 1, res);
        return res;
    }
};
int main(){
    int n = 4; vector<vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    Solution *s = new Solution();
    cout<<s->minScore(n, roads)<<endl;
    return 0;
}