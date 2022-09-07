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
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string res = "";
        res += to_string(root->val);
        if(root->left) res += "(" + tree2str(root->left) + ")";
        else if(root->right) res += "()";
        if(root->right) res += "(" + tree2str(root->right) + ")";
        return res;
    }
};
int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;

    Solution s;
    cout<<s.tree2str(p1)<<endl;
    return 0;
}