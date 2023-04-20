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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int size = 0, res = 0, d = 0;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            size = q.size();
            if(size == 1){
                q.push({q.front().first, 1});
                q.pop();
            }
            d = q.back().second - q.front().second + 1;
            res = max(res, d);
            while(size--){
                if(q.front().first->left) q.push({q.front().first->left, (q.front().second) * 2});
                if(q.front().first->right) q.push({q.front().first->right, ((q.front().second) * 2) + 1});
                q.pop();
            }
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
    cout<<s->widthOfBinaryTree(p1)<<endl;
    return 0;
}