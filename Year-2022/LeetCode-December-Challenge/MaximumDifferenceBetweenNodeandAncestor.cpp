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
    int helper(TreeNode *root, int minVal, int maxVal){
        if(!root) return maxVal - minVal;
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        return max(helper(root->left, minVal, maxVal), helper(root->right, minVal, maxVal));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int minVal = 10000, maxVal = 0;
        return helper(root, minVal, maxVal);
    }
};
int main(){
    TreeNode *p1 = new TreeNode(8);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(10);
    TreeNode *p4 = new TreeNode(1);
    TreeNode *p5 = new TreeNode(6);
    TreeNode *p6 = new TreeNode(14);
    TreeNode *p7 = new TreeNode(4);
    TreeNode *p8 = new TreeNode(7);
    TreeNode *p9 = new TreeNode(13);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p5->left = p7;
    p5->right = p8;
    p6->left = p9;

    Solution *s = new Solution();
    cout<<s->maxAncestorDiff(p1)<<endl;
    return 0;
}
