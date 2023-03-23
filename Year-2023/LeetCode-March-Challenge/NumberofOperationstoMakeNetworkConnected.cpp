#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void DFS(vector<vector<int>> &adj, vector<bool> &visited, int node){
        visited[node] = true;
        for(auto x: adj[node]){
            if(!visited[x]){
                DFS(adj, visited, x);
            }
        }
        return;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<vector<int>> adj(n);
        for(auto x: connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                DFS(adj, visited, i);
                count++;
            }
        }
        return count - 1;
    }
};

int main(){
    int n = 4; vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    Solution *s = new Solution();
    cout<<s->makeConnected(n, connections)<<endl;
    return 0;
}