#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        for(auto edge: edges) visited[edge[1]] = true;
        vector<int> res;
        for(int i = 0; i < n; ++i) 
            if(!visited[i]) res.push_back(i);
        return res;
    }
};
int main(){
    vector<vector<int>>  edges = {{0,1},{2,1},{3,1},{1,4},{2,4}};
    int n = 5;
    Solution *s = new Solution();
    vector<int> res = s->findSmallestSetOfVertices(n, edges);
    for(auto x: res) cout<<x<<" ";
    return 0;
}