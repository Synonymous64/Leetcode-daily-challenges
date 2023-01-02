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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right && targetSum == root->val) return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
int main(){
    TreeNode *p1 = new TreeNode(5);
    TreeNode *p2 = new TreeNode(4);
    TreeNode *p3 = new TreeNode(8);
    TreeNode *p4 = new TreeNode(11);
    TreeNode *p5 = new TreeNode(13);
    TreeNode *p6 = new TreeNode(4);
    TreeNode *p7 = new TreeNode(7);
    TreeNode *p8 = new TreeNode(2);
    TreeNode *p9 = new TreeNode(1);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->left = p5;
    p3->right = p6;
    p4->left = p7;
    p4->right = p8;
    p6->left = p9;
    int targetSum = 22;
    Solution s;
    cout<<std::boolalpha<<s.hasPathSum(p1, targetSum)<<endl;
    return 0;

}