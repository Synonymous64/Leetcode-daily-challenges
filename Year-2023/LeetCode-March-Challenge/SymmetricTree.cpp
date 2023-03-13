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
    bool helper(TreeNode *left, TreeNode *right){
        if(!left && !right) return true;
        if((!left && right) || (!right && left) || (left->val != right->val)) return false;
        return helper(left->right, right->left) && helper(left->left, right->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }
};

int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(2);
    TreeNode *p4 = new TreeNode(3);
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(4);
    TreeNode *p7 = new TreeNode(3);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;

    Solution *s = new Solution();
    cout<<std::boolalpha<<s->isSymmetric(p1)<<endl;
    return 0;
}