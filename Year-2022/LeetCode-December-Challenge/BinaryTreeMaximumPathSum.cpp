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
    int helper(TreeNode *root, int &maxSum){
        if(!root) return 0;
        int left = max(0, helper(root->left, maxSum));
        int right = max(0, helper(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
};
int main(){
    TreeNode *p1 = new TreeNode(-10);
    TreeNode *p2 = new TreeNode(9);
    TreeNode *p3 = new TreeNode(20);
    TreeNode *p4 = new TreeNode(15);
    TreeNode *p5 = new TreeNode(7);
    p1->left = p2;
    p1->right = p3;
    p3->left = p4;
    p3->right = p5;

    Solution *S = new Solution();
    cout<<S->maxPathSum(p1)<<endl;
    return 0;
}