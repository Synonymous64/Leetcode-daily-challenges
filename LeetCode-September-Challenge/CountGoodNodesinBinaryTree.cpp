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
    int count = 0;
    void countGoodNodes(TreeNode *root, int randMax){
        if(!root) return;
        if(root->val >= randMax) count++, randMax = root->val;
        countGoodNodes(root->left, randMax);
        countGoodNodes(root->right, randMax);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return count;
        countGoodNodes(root, root->val);
        return count;
    }
};
int main(){
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(1);
    TreeNode *p3 = new TreeNode(4);
    TreeNode *p4 = new TreeNode(3);
    TreeNode *p5 = new TreeNode(1);
    TreeNode *p6 = new TreeNode(5);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->left = p5;
    p3->right = p6;

    Solution s;
    cout<<s.goodNodes(p1)<<endl;
    return 0;
}