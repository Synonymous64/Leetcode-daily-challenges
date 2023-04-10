#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isValidParenthesis(char a, char b){
        if(a == '(' && b == ')') return true;
        else if(a == '[' && b == ']') return true;
        else if(a == '{' && b == '}') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> myStack; char checker;
        for(auto ch: s){
            if(ch == '(' || ch == '{' || ch == '[') myStack.push(ch);
            else if(ch == ')' || ch == '}' || ch == ']'){
                if(myStack.empty()) return false;
                checker = myStack.top();
                if(!isValidParenthesis(checker, ch)) return false;
                else myStack.pop();
            }
        }
        return myStack.empty() ? true: false;
    }
};
int main(){
    string s = "()[]{}";
    Solution *S = new Solution();
    cout<<std::boolalpha<<S->isValid(s)<<endl;
    return 0;
}