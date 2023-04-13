#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int top = 0; stack<int> myStack;
        for(auto ch: pushed){
            myStack.push(ch);
            while(!myStack.empty() && myStack.top() == popped[top]){
                myStack.pop();
                top++;
            }
        }
        return myStack.empty();
    }
};
int main(){
    vector<int> pushed = {1,2,3,4,5}, popped = {4,5,3,2,1};
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->validateStackSequences(pushed, popped)<<endl;
    return 0;
}