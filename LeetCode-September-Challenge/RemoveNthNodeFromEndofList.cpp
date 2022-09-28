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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        for(int i = 1; i <= n; ++i) p = p->next;
        ListNode *q = head;
        if(p){
            while(p->next){
                p = p->next;
                q = q->next;
            }
            ListNode *temp = q->next;
            q->next = temp->next;
            delete temp;
        } else{
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        return head;
    }
    void printCode(ListNode *head){
        if(!head) return;
        ListNode *temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};
int main(){
    Solution s;
    ListNode *head = s.createLL(head, 5);
    ListNode *head2 = s.removeNthFromEnd(head, 2);
    s.printCode(head2);
    return 0; 
}