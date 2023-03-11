#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    vector<int> res;
    void toArr(ListNode *head){
        ListNode *temp = head;
        while(temp){
            res.push_back(temp->val);
            temp = temp->next;
        }
        return;
    }
    TreeNode *arrBST(vector<int> &nums, int low, int high){
        if(low >= high) return nullptr;
        int mid = low + (high - low)/2;
        TreeNode *newTree = new TreeNode(nums[mid]);
        newTree->left = arrBST(nums, low, mid);
        newTree->right = arrBST(nums, mid + 1, high);
        return newTree;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        toArr(head);
        return arrBST(res, 0, res.size());
    }
};