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
    void helper(TreeNode *root, int targetSum, vector<int> temp, vector<vector<int>> &res){
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum) res.push_back(temp);
        helper(root->left, targetSum - root->val, temp, res);
        helper(root->right, targetSum - root->val, temp, res);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        helper(root, targetSum, {}, res);
        return res;
    }
    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    }
};
int main(){
    TreeNode *p1 = new TreeNode(5);
    TreeNode *p2 = new TreeNode(4);
    TreeNode *p3 = new TreeNode(8);
    TreeNode *p4 = new TreeNode(11);
    TreeNode *p5 = new TreeNode(13);
    TreeNode *p6 = new TreeNode(4);
    TreeNode *p7 = new TreeNode(7);
    TreeNode *p8 = new TreeNode(2);
    TreeNode *p9 = new TreeNode(5);
    TreeNode *p10 = new TreeNode(1);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->left = p5;
    p3->right = p6;
    p4->left = p7;
    p4->right = p8;
    p6->left = p9;
    p6->right = p10;

    Solution s;
    vector<vector<int>> res = s.pathSum(p1, 22);
    for(int i = 0; i < res.size(); ++i){
        s.printCode(res[i]);
    }
    return 0;
}