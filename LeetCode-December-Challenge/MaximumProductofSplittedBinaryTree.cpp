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
    long long totalSum = 0, res = 0;
    int MOD = 1e9+7;
    int helper(TreeNode *root){
        if(!root) return 0;
        long long sum = 0;
        sum += helper(root->left) + helper(root->right) + root->val;
        res = max(res, (totalSum - sum) * sum);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        totalSum = helper(root);
        helper(root);
        return res % MOD;
    }
};
int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);
    TreeNode *p6 = new TreeNode(6);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;

    Solution *S = new Solution();
    cout<<S->maxProduct(p1)<<endl;
    return 0;
}