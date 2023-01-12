#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> res;
    vector<vector<int>> graph;
    vector<int> DFS(int start, int parent, string &labels){
        vector<int> ans(26, 0);
        ans[labels[start] - 'a']++;
        for(auto x: graph[start]){
            if(x == parent) continue;
            vector<int> hsh = DFS(x, start, labels);
            for(int i = 0; i < 26; ++i){
                ans[i] += hsh[i];
            }
        }
        res[start] = ans[labels[start] - 'a'];
        return ans;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        res.resize(n, 0);
        graph.resize(n, vector<int> {});
        for(auto x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        DFS(0, -1, labels);
        return res;
    }
};
int main(){
    int n = 7;
    vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    string labels = "abaedcd";
    Solution *s = new Solution();
    vector<int> res = s->countSubTrees(n, edges, labels);
    for(int x: res) cout<<x<<" ";
    return 0;
}