#include<bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(){}
};
class ListNode *createLL(ListNode *head, int limit){
    if(limit == 0){
        cout<<"Linked List is Empty"<<endl;
        return NULL;
    }
    ListNode *newNode = nullptr, *temp = nullptr;
    int data = 0;
    cout<<"Enter the element of the linked list till " <<limit<<endl;
    head = new ListNode;
    cin>>data;
    head->val = data;
    head->next = NULL;
    temp = head;
    for(int i = 2; i <= limit; ++i){
        newNode = new ListNode;
        cin>>data;
        newNode->val = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
void reverseLL(ListNode **head){
    ListNode *prev = NULL, *curr = (*head), *newNode = NULL;
    while(curr){
        newNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = newNode;
    }
    (*head) = prev;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA, *p2 = headB;
    while(p1 != p2){
        p1 = p1 ? p1->next : headA;
        p2 = p2 ? p2->next : headB;
    }
    return p1;
}

void displayList(ListNode *head){
    ListNode *temp = head;
    if(!temp) cout<<"Empty List"<<endl;
    else{
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
    return;
}
int main(){
    int m, n;
    cin>>m>>n;
    ListNode *head = createLL(head, m);
    cout<<"For Head 2"<<endl;
    ListNode *head2 = createLL(head2, n);
    ListNode *head = getIntersectionNode(head, head2);
    displayList(head);
    return 0;
}
