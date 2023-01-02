#include<bits/stdc++.h>
using namespace std;
class ListNode{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *createLL(ListNode *head, int limit){
    if(!limit) return NULL;
    else{
        ListNode *newTree = nullptr, *temp = nullptr;
        int data;
        head = new ListNode;
        cin>>data;
        head->next = nullptr;
        head->val = data;
        temp = head;
        for(int i = 1; i < limit; ++i){
            newTree = new ListNode;
            cin>>data;
            newTree->val = data;
            newTree->next = nullptr;
            temp->next = newTree;
            temp = temp->next;
        }
    }
    return head;
}
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev = nullptr, *temp = nullptr, *tail = nullptr;
        ListNode dummy(NULL);
        prev = &dummy;
        dummy.next = head;
        for(int i = 0; i < left - 1; ++i) prev = prev->next;
        tail = prev->next;
        for(int i = 0; i < right - left; ++i){
            temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp;
        }
        return dummy.next;
    }
};
void printLL(ListNode *head){
    ListNode *temp = head;
    if(!temp) return;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    } cout<<endl;
}
int main(){
    ListNode *head = createLL(head, 5);
    printLL(head);
    Solution s;
    ListNode *head2 = s.reverseBetween(head, 2, 4);
    printLL(head2);
    return 0;
}