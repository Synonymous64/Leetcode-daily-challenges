#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool DFS(vector<vector<int>> &graph, vector<int> &color, int idx){
        for(auto x: graph[idx]){
            if(color[x] == -1){
                color[x] = 1 - color[idx];
                if(!DFS(graph, color, x)) return false;
            }
            else if(color[x] == color[idx]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; ++i){
            if(color[i] == -1){
                color[i] = 1;
                if(!DFS(graph, color, i)) return false;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->isBipartite(graph)<<endl;
    return 0;
}