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
    void inorderTraversal(TreeNode *root, vector<int> &res){
        if(root){
            inorderTraversal(root->left, res);
            res.push_back(root->val);
            inorderTraversal(root->right, res);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorderTraversal(root, res);
        int start = 0, end = res.size() - 1;
        while(start < end){
            if(res[start] + res[end] == k) return true;
            else if(res[start] + res[end] < k) start++;
            else end--;
        }
        return false;
    }
};
int main(){
    TreeNode *p1 = new TreeNode(5);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(6);
    TreeNode *p4 = new TreeNode(2);
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(7);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;

    Solution s;
    cout<<boolalpha<<s.findTarget(p1, 9)<<endl;
    return 0;
}