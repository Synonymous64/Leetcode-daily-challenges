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
    int res;
    void inorderTraversal(TreeNode *root, int low, int high){
        if(root){
            inorderTraversal(root->left, low, high);
            if(root->val >= low && root->val <= high) res += root->val;
            inorderTraversal(root->right, low, high);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        inorderTraversal(root, low, high);
        return res;
    }
};
int main(){
    TreeNode *p1 = new TreeNode (10);
    TreeNode *p2 = new TreeNode (5);
    TreeNode *p3 = new TreeNode (15);
    TreeNode *p4 = new TreeNode (3);
    TreeNode *p5 = new TreeNode (7);
    TreeNode *p6 = new TreeNode (18);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->right = p6;

    Solution *s = new Solution();
    int low = 7, high = 15;
    cout<<s->rangeSumBST(p1, low, high)<<endl;
    return 0;
}