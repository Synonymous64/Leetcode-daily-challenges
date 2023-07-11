#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool flag = false;
    void check(TreeNode *root, TreeNode *target, unordered_map<TreeNode *, TreeNode *> &parent){
        if(!root) return;
        if(root->val == target->val) flag = true;
        parent[root->left] = root;
        parent[root->right] = root;
        check(root->left, target, parent);
        check(root->right, target, parent);
        return;
    }
    void solve(TreeNode *root, int k, vector<int> &res, unordered_map<TreeNode *, TreeNode *> &parent, unordered_map<TreeNode *, int> &visited, int h){
        if(!root) return;
        if(visited.find(root) != visited.end()) return;
        visited[root] = h + 1;

        if(k == h) res.push_back(root->val);
        solve(root->left, k, res, parent, visited, h + 1);
        solve(root->right, k, res, parent, visited, h + 1);
        solve(parent[root], k, res, parent, visited, visited[root]);
        return;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, TreeNode *> parent;
        unordered_map<TreeNode *, int> visited;
        vector<int> res;

        check(root, target, parent);

        if(!root || !flag) return res;
        solve(target, k, res, parent, visited, 0);
        return res;
    }
};

int main(){
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(5);
    TreeNode *p3 = new TreeNode(1);
    TreeNode *p4 = new TreeNode(6);
    TreeNode *p5 = new TreeNode(2);
    TreeNode *p6 = new TreeNode(0);
    TreeNode *p7 = new TreeNode(8);
    TreeNode *p8 = new TreeNode(7);
    TreeNode *p9 = new TreeNode(4);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    p5->left = p8;
    p5->right = p9;
    int k = 2;
    Solution *s = new Solution();
    vector<int> res = s->distanceK(p1, p2, k);
    for(auto x: res) cout<<x<<" ";
    return 0;
}