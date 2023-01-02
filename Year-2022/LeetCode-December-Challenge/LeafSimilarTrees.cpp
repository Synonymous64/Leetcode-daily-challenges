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
    void helper(TreeNode *root, string &s){
        if(!root) return;
        if(!root->left && !root->right) s += to_string(root->val) + '.';
        helper(root->left, s);
        helper(root->right, s);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "", s2 = "";
        helper(root1, s1);
        helper(root2, s2);
        return s1 == s2;
    }
};
int main(){
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(5);
    TreeNode *p3 = new TreeNode(1);
    TreeNode *p4 = new TreeNode(6);
    TreeNode *p5 = new TreeNode(2);
    TreeNode *p6 = new TreeNode(9);
    TreeNode *p7 = new TreeNode(8);
    TreeNode *p8 = new TreeNode(7);
    TreeNode *p9 = new TreeNode(4);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    p5->left = p8;
    p5->right = p9;

    TreeNode *q1 = new TreeNode (3);
    TreeNode *q2 = new TreeNode (5);
    TreeNode *q3 = new TreeNode (1);
    TreeNode *q4 = new TreeNode (6);
    TreeNode *q5 = new TreeNode (7);
    TreeNode *q6 = new TreeNode (4);
    TreeNode *q7 = new TreeNode (2);
    TreeNode *q8 = new TreeNode (9);
    TreeNode *q9 = new TreeNode (8);

    q1->left = q2;
    q1->right = q3;
    q2->left = q4;
    q2->right = q5;
    q3->left = q6;
    q3->right = q7;
    q7->left = q8;
    q7->right = q9;

    Solution *s = new Solution();
    cout<<std::boolalpha<<s->leafSimilar(p1, q1)<<endl;
    return 0;
}