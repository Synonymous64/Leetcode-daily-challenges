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
    ListNode *reverseList(ListNode **head){
        ListNode *prev = nullptr, *curr  = *(head), *newNode = nullptr;
        while(curr){
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        *(head) = prev;
        return prev;
    }
public:
    ListNode *createBT(ListNode *root, int key){
        if(!key) return nullptr;
        ListNode *newNode = nullptr, *temp = nullptr;
        int data = 0;
        cin>>data;
        root = new ListNode(data);
        root->next = nullptr;
        temp = root;
        for(int i = 2; i <= key; ++i){
            cin>>data;
            newNode = new ListNode(data); 
            newNode->next = nullptr;
            temp->next = newNode;
            temp = temp->next;
        }
        return root;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast != nullptr) slow = slow->next;
        ListNode *reverseHead = reverseList(&slow);
        while(reverseHead){
            if(reverseHead->val == head->val){
                reverseHead = reverseHead->next;
                head = head->next;
            } else return false;
        }
        return true;
    }
    void printCode(ListNode *root){
        ListNode *temp = root;
        if(!temp) cout<<"Empty Code";
        else {
            while(temp){
                cout<<temp->val<<" ";
                temp = temp->next;
            } cout<<endl;
        }
    }
};
int main(){
    Solution s;
    ListNode *root = s.createBT(root, 4);
    cout<<std::boolalpha<<s.isPalindrome(root)<<endl;
    return 0; 
}