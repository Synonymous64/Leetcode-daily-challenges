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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = head;
        while(--k) first = first->next;
        ListNode *temp = first;
        ListNode *second = head;
        while(temp->next){
            temp = temp->next;
            second = second->next;
        }
        swap(first->val, second->val);
        return head;
    }
    void reverseLL(ListNode **head){
        ListNode *newNode = nullptr, *prev = nullptr,  *curr = *(head);
        while(curr){
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        *(head) = prev;
    }
    void printLL(ListNode *head){
        if(!head) return;
        ListNode *temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        return;
    }
};

int main(){
    Solution *s = new Solution();
    ListNode *head = s->createLL(head, 5);
    // s->reverseLL(&head);
    head = s->swapNodes(head, 2);
    s->printLL(head);
    return 0;
}