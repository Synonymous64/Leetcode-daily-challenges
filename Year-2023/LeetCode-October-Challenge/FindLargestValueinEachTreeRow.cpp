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
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int maxVal = INT_MIN;
            while(size--){
                TreeNode *curr = q.front();
                q.pop();
                maxVal = max(maxVal, curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};

int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(2);
    TreeNode *p4 = new TreeNode(5);
    TreeNode *p5 = new TreeNode(3);
    TreeNode *p6 = new TreeNode(9);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->right = p6;

    Solution *s = new Solution();
    vector<int> res = s->largestValues(p1);
    for(auto ch: res) cout<<ch<<" ";
    return 0;
}