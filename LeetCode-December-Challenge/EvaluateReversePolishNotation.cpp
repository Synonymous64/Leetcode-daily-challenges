#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto str: tokens){
            if(str.size() > 1 || isdigit(str[0])) st.push(stoi(str));
            else{
                long long int x2 = st.top(); st.pop();
                long long int x1 = st.top(); st.pop();
                switch(str[0]){
                    case '+': x1 += x2; break;
                    case '-': x1 -= x2; break;
                    case '*': x1 *= x2; break;
                    case '/': x1 /= x2; break;
                }
                st.push(x1);
            }
        }
        return st.top();
    }
};
int main(){
    vector<string> tokens = {"2","1","+","3","*"};
    Solution *s = new Solution();
    cout<<s->evalRPN(tokens)<<endl;
    return 0;
}