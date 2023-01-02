//!------------------<o(n)>---------------------------- 
// #include<bits/stdc++.h>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// class Solution {
// private:
//     int count;
//     void helper(TreeNode *root){
//         if(root){
//             helper(root->left);
//             count++;
//             helper(root->right);
//         }
//     }
// public:
//     int countNodes(TreeNode* root) {
//         if(!root) return 0;
//         helper(root);
//         return count;
//     }
// };
// int main(){
//     TreeNode *p1 = new TreeNode(1);
//     TreeNode *p2 = new TreeNode(2);
//     TreeNode *p3 = new TreeNode(3);
//     TreeNode *p4 = new TreeNode(4);
//     TreeNode *p5 = new TreeNode(5);
//     TreeNode *p6 = new TreeNode(6);

//     p1->left = p2;
//     p1->right = p3;
//     p2->left = p4;
//     p2->right = p5;
//     p3->left = p6;

//     Solution *s = new Solution();
//     cout<<s->countNodes(p1)<<endl;
//     return 0;
// }

//! -----------------------------<o(log * log)>------------------------
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
    int helper(TreeNode *root,int leftCount = 1, int rightCount = 1){
        if(!root) return 0;
        TreeNode *lefty = root, *righty = root;
        while(lefty = lefty->left) leftCount++;
        while(righty = righty->right) rightCount++;
        if(leftCount == rightCount) return (1 << leftCount) - 1;
        return 1 + helper(root->left) + helper(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        return helper(root);
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

    Solution *s = new Solution();
    cout<<s->countNodes(p1)<<endl;
    return 0;
}