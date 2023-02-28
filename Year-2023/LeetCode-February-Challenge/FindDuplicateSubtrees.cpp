#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    string helper(TreeNode *root, unordered_map<string, int> &mp, vector<TreeNode *> &res){
        if(!root) return "";
        string s = to_string(root->val) + "," + helper(root->left, mp, res) + "," + helper(root->right, mp, res);
        mp[s]++;
        if(mp[s] == 2) res.push_back(root);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode *> res;
        helper(root, mp, res);
        return res;
    }
};
int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(2);
    TreeNode *p6 = new TreeNode(4);
    TreeNode *p7 = new TreeNode(4);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->left = p5;
    p3->right = p6;
    p5->left = p7;

    Solution *s = new Solution();
    vector<TreeNode *> res = s->findDuplicateSubtrees(p1);
    for(auto ch: res){
        if(ch->right) ch = ch->right;
        cout<<ch->val<<" ";
        if(ch->left) ch = ch->left;
    }
}