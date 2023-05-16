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
    ListNode *createLL(ListNode *head, int limit){
        if(!limit) return nullptr;
        ListNode *temp = nullptr, *newNode = nullptr;
        int data = 0;
        cin>>data;
        head = new ListNode(data);
        head->next = nullptr;
        temp = head;
        for(int i = 1; i < limit; ++i){
            cin>>data;
            newNode = new ListNode(data);
            newNode->next = nullptr;
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummy = new ListNode();
        ListNode *prev = dummy;
        ListNode *curr = head;
        while(curr && curr->next){
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;

            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
    void printLL(ListNode *head) {
        if(!head) return;
        ListNode *temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    Solution *s = new Solution();
    ListNode *head = s->createLL(head, 4);
    head = s->swapPairs(head);
    s->printLL(head);
    return 0;
}