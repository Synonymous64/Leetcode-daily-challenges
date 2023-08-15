#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;
        ListNode *smallerEli = new ListNode(-1);
        ListNode *greaterEli = new ListNode(-1);
        smallerEli->next = head;
        greaterEli->next = head;

        ListNode *smallerHead = smallerEli;
        ListNode *greaterHead = greaterEli;

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
        smallerEli->next = greaterHead->next;
        return smallerHead->next;
    }
};

void printLL(ListNode *head){
    ListNode *temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    return;
}

int main(){
    ListNode *head = createLL(head, 6);
    Solution *s = new Solution();
    ListNode *head2 = s->partition(head, 3);
    printLL(head2);
    return 0;
}