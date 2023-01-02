#include<bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int value) : val(value), next(nullptr){}
    ListNode(int value, ListNode *root) : val(value), next(root){}
};
ListNode *createLL(ListNode *head, int limit){
    if(!limit) return NULL;
    ListNode *temp = nullptr, *newNode = nullptr;
    int data = 0;
    head = new ListNode;
    cin>>data;
    head->val = data;
    head->next = nullptr;
    temp = head;
    for(int i = 1; i < limit; ++i){
        newNode = new ListNode;
        cin>>data;
        newNode->val = data;
        newNode->next = nullptr;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
void printLL(ListNode *head){
    if(!head) return;
    ListNode *temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    } cout<<endl;
}
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode *smallerEli = new ListNode(-1);
        ListNode *greaterEli = new ListNode(-1);
        smallerEli->next = head;
        greaterEli->next = head;
        ListNode *smallerHeadEli = smallerEli;
        ListNode *greaterHeadEli = greaterEli;
        while(head){
            if(head->val < x){
                smallerEli->next = head;
                smallerEli = smallerEli->next;
            } else{
                greaterEli->next = head;
                greaterEli = greaterEli->next;
            }
            head = head->next;
        }
        greaterEli->next = nullptr;
        smallerEli->next = greaterHeadEli->next;
        return smallerHeadEli->next;
    }
};
int main(){
    ListNode *head = createLL(head, 6);
    printLL(head);
    Solution s;
    ListNode *head2 = s.partition(head, 3);
    printLL(head2);
    return 0; 
}