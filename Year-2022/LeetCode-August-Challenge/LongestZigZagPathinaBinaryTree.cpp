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
    int res = 0;
    void helper(TreeNode *root, bool check, int checkSteps){
        if(!root) return;
        res = max(res, checkSteps);
        if(check){
            helper(root->left, false, checkSteps + 1);
            helper(root->right, true, 1);
        } else{
            helper(root->right, true, checkSteps + 1);
            helper(root->left, false, 1);
        }
        return;
    }
public:
    int longestZigZag(TreeNode* root) {
        helper(root, true, 0);
        helper(root, false, 0);
        return res;
    }
};

int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(1);
    TreeNode *p3 = new TreeNode(1);
    TreeNode *p4 = new TreeNode(1);
    TreeNode *p5 = new TreeNode(1);
    TreeNode *p6 = new TreeNode(1);
    TreeNode *p7 = new TreeNode(1);

    p1->left = p2;
    p1->right = p3;
    p2->right = p4;
    p4->left = p5;
    p4->right = p6;
    p5->right = p7;

    Solution *s = new Solution();
    cout<<s->longestZigZag(p1)<<endl;
    return 0;

}
