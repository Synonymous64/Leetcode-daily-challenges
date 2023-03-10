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
private:
    int count = 0;
    ListNode *headNode = nullptr;
public:
    Solution(ListNode* head) {
        headNode = head;
        ListNode *temp = headNode;
        while(temp){
            count++;
            temp = temp->next;
        }
    }

    int getRandom() {
        int randomIndex = rand() % count;
        ListNode *temp = headNode;
        for(int i = 0; i < randomIndex; ++i){
            temp = temp->next;
        }
        return temp->val;
    }
};