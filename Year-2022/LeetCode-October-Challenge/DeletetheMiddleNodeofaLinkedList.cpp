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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode *fast = head->next->next;
        ListNode *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return head;
    }
    void printLL(ListNode *head){
        ListNode *temp = head;
        if(!temp) return;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};
int main(){
    Solution s;
    ListNode *head = s.createLL(head, 7);
    s.deleteMiddle(head);
    s.printLL(head);
    return 0; 
}