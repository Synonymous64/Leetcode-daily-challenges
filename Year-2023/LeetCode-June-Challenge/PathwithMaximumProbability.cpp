#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); ++i){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        vector<double> v(n, 0);

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            if(curr.second == end) return curr.first;

            for(auto neighbour: adj[curr.second]){
                if(v[neighbour.first] < curr.first * neighbour.second){
                    v[neighbour.first] = curr.first * neighbour.second;
                    pq.push({v[neighbour.first], neighbour.first});
                }
            }
        }

        return 0;
    }
};

int main(){
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    int start = 0, end = 2;
    Solution *s = new Solution();
    cout<<s->maxProbability(n, edges, succProb, start, end)<<endl;
    return 0;
}