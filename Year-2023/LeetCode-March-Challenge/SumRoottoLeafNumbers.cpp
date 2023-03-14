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
    int sumNumbers(TreeNode* root, int sum = 0) {
        if(!root) return 0;
        sum = sum * 10 + root->val;
        if(!root->left && !root->right)return sum;
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
};
int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);

    p1->left = p2;
    p1->right = p3;

    Solution *s = new Solution();
    cout<<s->sumNumbers(p1)<<endl;
    return 0;
}