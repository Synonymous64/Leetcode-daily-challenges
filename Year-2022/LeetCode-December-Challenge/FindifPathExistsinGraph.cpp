#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int top = q.front();
            if(top == destination) return true;
            q.pop();
            for(auto x: adj[top]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return false;
    }
};
int main(){
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}}; 
    int source = 0, destination = 2, n = 3;
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->validPath(n, edges, source, destination)<<endl;
    return 0;
}