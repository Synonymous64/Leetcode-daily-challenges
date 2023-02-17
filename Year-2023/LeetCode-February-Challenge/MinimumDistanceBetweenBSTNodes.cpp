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
    vector<int> res;
    void inorderTraversal(TreeNode *root){
        if(root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
    }
public:
    int minDiffInBST(TreeNode* root) {
        int minVal = INT_MAX;
        inorderTraversal(root);
        for(int i = 0; i < res.size() - 1; ++i)
            minVal = min(minVal, res[i + 1] - res[i]);
        return minVal;
    }
};
int main(){
    TreeNode *p1 = new TreeNode(4);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(6);
    TreeNode *p4 = new TreeNode(1);
    TreeNode *p5 = new TreeNode(3);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    Solution *s = new Solution();
    cout<<s->minDiffInBST(p1)<<endl;
    return 0;
}