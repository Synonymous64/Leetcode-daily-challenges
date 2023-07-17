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
private:
    void reverseLL(ListNode **head){
        ListNode *prev = nullptr, *curr = *(head), *newNode = nullptr;
        while(curr){
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        *(head) = prev;
    }
public:
    ListNode *createBT(ListNode *head, int limit){
        if(!limit) return nullptr;
        ListNode *temp = nullptr, *newNode = nullptr;
        int data;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverseLL(&l1);
        reverseLL(&l2);

        ListNode *res = new ListNode(0);
        ListNode *curr = res;
        int carry = 0;

        while(l1 || l2 || carry){
            int sum = 0;

            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            ListNode *temp = new ListNode(sum % 10);
            curr->next = temp;
            curr = curr->next;
        }
        reverseLL(&res->next);
        return res->next;
    }
    void printCode(ListNode *head){
        if(!head) return;
        ListNode *curr = head;
        while(curr){
            cout<<curr->val<<" ";
            curr = curr->next;
        }
    }
};

int main(){
    Solution *s = new Solution();
    ListNode *head1 = s->createBT(head1, 4);
    ListNode *head2 = s->createBT(head2, 3);
    ListNode *res = s->addTwoNumbers(head1, head2);
    s->printCode(res);
    return 0;
}