#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> myStack;
        for(int i = 0;i < temperatures.size(); ++i){
            while(!myStack.empty() && temperatures[myStack.top()] < temperatures[i])
                res[myStack.top()] = i - myStack.top(), myStack.pop();
            myStack.push(i);
        }
        return res;
    }
};
int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution *s = new Solution();
    vector<int> res = s->dailyTemperatures(temperatures);
    for(int i = 0; i < res.size(); ++i) cout<<res[i]<<" ";
    return 0;
}