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
    void preorder(TreeNode *root, map<int, vector<pair<int,int>>> &mp, int level, int vertical){
        if(!root) return;
        mp[vertical].push_back({level, root->val});
        preorder(root->left, mp, level + 1, vertical - 1);
        preorder(root->right, mp, level + 1, vertical + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;
        preorder(root, mp, 0, 0);
        vector<vector<int>> res;
        for(auto i : mp){
            sort(i.second.begin(), i.second.end());
            vector<int> temp;
            for(auto pair : i.second){
                temp.push_back(pair.second);
            }
            res.push_back(temp);
        }
        return res;
    }
    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i){
            cout<<nums[i]<<" ";
        }
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
    p3->right = p5;

    Solution s;
    vector<vector<int>> res = s.verticalTraversal(p1);
    for(int i = 0; i < res.size(); ++i) s.printCode(res[i]);
    return 0;
}