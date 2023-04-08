#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node *, Node*> mp;
        if(!node) return nullptr;
        Node *first = new Node(node->val, {});
        mp[node] = first;
        queue<Node *> q;
        q.push(node);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto adj: curr->neighbors){
                if(!mp[adj]){
                    mp[adj] = new Node(adj->val, {});
                    q.push(adj);
                }
                mp[curr]->neighbors.push_back(mp[adj]);
            }
        }
        return mp[node];
    }
};