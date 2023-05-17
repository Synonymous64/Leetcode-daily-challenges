#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> list;
        ListNode *temp = head;
        while(temp){
            list.push_back(temp->val);
            temp = temp->next;
        }
        int res = 0, n = list.size();
        for(int i = 0; i < n/2; ++i){
            res = max(res, list[i] + list[n - 1 - i]);
        }
        return res;
    }
};