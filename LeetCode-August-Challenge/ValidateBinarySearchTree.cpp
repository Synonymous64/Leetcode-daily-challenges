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
    bool isBST(TreeNode *root, TreeNode *minimum = nullptr, TreeNode *maximum = nullptr){
        if(!root) return true;
        if(minimum && root->val <= minimum->val) return false;
        if(maximum && root->val >= maximum->val) return false;
        bool leftValid = isBST(root->left, minimum, root);
        bool rightValid = isBST(root->right, root, maximum);
        return leftValid & rightValid;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
};
int main(){
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(1);
    TreeNode *p3 = new TreeNode(3);
    p1->left = p2;
    p1->right = p3;

    Solution s;
    cout<<::std::boolalpha<<s.isValidBST(p1)<<endl;
    return 0;

}