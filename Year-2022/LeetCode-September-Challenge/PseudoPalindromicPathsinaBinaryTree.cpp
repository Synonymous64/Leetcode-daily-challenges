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
    void DFS(TreeNode *root, vector<int> Freq, int &count){
        if(!root) return;
        Freq[root->val]++;
        DFS(root->left, Freq, count);
        if(root->left == nullptr && root->right == nullptr){
            int getCount = 0;
            for(auto i : Freq)
                if(i % 2 == 1) getCount++;
            if(getCount <= 1) count++;
        }
        DFS(root->right, Freq, count);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> Freq(10, 0); int count = 0;
        DFS(root, Freq, count);
        return count;
    }
};
int main(){
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(1);
    TreeNode *p4 = new TreeNode(3);
    TreeNode *p5 = new TreeNode(1);
    TreeNode *p6 = new TreeNode(1);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->right = p6;

    Solution s;
    cout<<s.pseudoPalindromicPaths(p1)<<endl;
    return 0;
}