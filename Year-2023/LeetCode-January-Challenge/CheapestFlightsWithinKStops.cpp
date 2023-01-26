#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < flights.size(); ++i)
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, src, 0});
        vector<int> noOfStops(n, INT_MAX);

        while(!pq.empty()){
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if(noOfStops[node] < stops) continue;
            noOfStops[node] = stops;

            if(node == dst) return cost;

            if(stops > k) continue;

            for(auto x: adj[node]){
                pq.push({cost + x.second, x.first, stops + 1});
            }
        }
        return -1;git
    }
};