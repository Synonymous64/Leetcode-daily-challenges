#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        vector<int> color(n + 1, 0);
        vector<bool> visited(n + 1, false);
        for(auto &x: dislikes){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        for(int i = 0; i <= n; ++i){
            if(!visited[i]){
                color[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    if(visited[curr]) continue;
                    visited[curr] = true;
                    for(auto x: adj[curr]){
                        if(color[x] == color[curr]) return false;
                        else if(color[curr] == 1) color[x] = 2;
                        else color[x] = 1;
                        q.push(x);
                    }
                }
            }
        }
        return true;
    }
};
int main(){
    int n = 4;
    vector<vector<int>> dislikes = {{1,2},{1,3},{2,4}};
    Solution *s = new Solution();
    cout<<boolalpha<<s->possibleBipartition(n, dislikes)<<endl;
    return 0;
}