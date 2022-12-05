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
    ListNode *createLL(ListNode *head, int key){
        if(!key) return nullptr;
        ListNode *newNode = nullptr, *temp = nullptr;
        int data = 0;
        cin>>data;
        head = new ListNode(data);
        temp = head;
        for(int i = 2; i <= key; ++i){
            cin>>data;
            newNode = new ListNode(data);
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
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
        ListNode *newNode = nullptr, *curr = *(head), *prev = nullptr;
        while(curr){
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        *head = prev;
    }
};
int main(){
    Solution *s = new Solution();
    ListNode *head = nullptr;
    head = s->createLL(head, 2);
    ListNode *res = s->middleNode(head);
    // s->reverseLL(&head);
    s->printLL(res);
    return 0;
}