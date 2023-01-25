#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void BFS(unordered_map<int,int> &dist, vector<bool> &visited, queue<int> &q, vector<int> adj[]){
        while(!q.empty()){
            int curr = q.front(); q.pop();
            for(auto neighbour: adj[curr]){
                if(!visited[neighbour]){
                    dist[neighbour] = dist[curr] + 1;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];

        for(int i = 0; i < n; ++i)
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);

        unordered_map<int,int> dist1, dist2;
        vector<bool> visited1(n, false), visited2(n, false);
        queue<int> q1, q2;

        dist1[node1] = 0;
        visited1[node1] = true;
        q1.push(node1);
        BFS(dist1, visited1, q1, adj);

        dist2[node2] = 0;
        visited2[node2] = true;
        q2.push(node2);
        BFS(dist2, visited2, q2, adj);

        int maxDist = INT_MAX, res = -1;
        for(auto it: dist1){
            int ele = it.first;
            if(dist2.find(ele) != dist2.end()){
                int currDist = max(dist1[ele], dist2[ele]);
                if(currDist < maxDist){
                    maxDist = currDist;
                    res = ele;
                } else if(maxDist == currDist && res > ele){
                    res = ele;
                }
            }
        }
        return res;
    }
};
int main(){
    vector<int> edges = {2,0,0}; int node1 = 2, node2 = 0;
    Solution *s = new Solution();
    cout<<s->closestMeetingNode(edges, node1, node2)<<endl;
    return 0;
}