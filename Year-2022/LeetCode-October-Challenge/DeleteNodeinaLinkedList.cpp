#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *createLL(ListNode *head, int limit){
        if(!limit) return nullptr;
        ListNode *newNode = nullptr, *temp = nullptr;
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    void printLL(ListNode *head){
        if(!head) return;
        ListNode *temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
    void reverseLL(ListNode **head){
        ListNode *newNode = nullptr, *curr = (*head), *prev = nullptr;
        while(curr){
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        (*head) = prev;
    }
};
int main(){
    Solution s;
    ListNode *head = s.createLL(head, 4);
    ListNode *temp = head->next;
    s.deleteNode(temp);
    s.printLL(head);

    return 0; 
}