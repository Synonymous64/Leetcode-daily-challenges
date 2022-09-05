#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node *> q;
        q.push(root); vector<vector<int>> res;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                Node *curr = q.front();
                q.pop();
                for(auto child : curr->children) q.push(child);
                temp.push_back(curr->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};