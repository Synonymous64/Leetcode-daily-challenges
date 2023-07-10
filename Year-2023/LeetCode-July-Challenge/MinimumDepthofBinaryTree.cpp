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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left = minDepth(root->left), right = minDepth(root->right);
        return 1 + (min(left, right) ? min(left, right) : max(left, right));
    }
};

int main(){
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(9);
    TreeNode *p3 = new TreeNode(20);
    TreeNode *p4 = new TreeNode(15);
    TreeNode *p5 = new TreeNode(7);

    p1->left = p2;
    p1->right = p3;
    p3->left = p4;
    p4->right = p5;

    Solution *s = new Solution();
    cout<<s->minDepth(p1)<<endl;
    return 0;
}