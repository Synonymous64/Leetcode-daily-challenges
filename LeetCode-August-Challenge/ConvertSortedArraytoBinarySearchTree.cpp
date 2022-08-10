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
    TreeNode *arrBST(vector<int> &nums, int low, int high){
        if(low >= high) return NULL;
        int mid = low + (high - low)/2;
        TreeNode *newTree = new TreeNode(nums[mid]);
        newTree->left = arrBST(nums, low, mid);
        newTree->right = arrBST(nums, mid + 1, high);
        return newTree;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrBST(nums, 0, nums.size());
    }
    void levelorder(TreeNode *root){
        if(!root) return;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode *curr = q.front();
                cout<<curr->val<<" ";
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
};
int main(){
    vector<int> nums = {-10,-3,0,5,9};
    Solution s;
    TreeNode *root = s.sortedArrayToBST(nums);
    s.levelorder(root);
    return 0;
}