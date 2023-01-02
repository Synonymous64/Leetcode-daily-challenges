#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), MOD = 1e9+7;
        vector<int> left(n), right(n);
        stack<pair<int,int>> myStack;
        for(int i = 0; i < n; ++i){
            int count = 1;
            while(!myStack.empty() && myStack.top().first > arr[i]){
                count += myStack.top().second;
                myStack.pop();
            }
            myStack.push({arr[i], count});
            left[i] = count;
        }
        while(!myStack.empty()) myStack.pop();
        for(int i = n - 1; i >= 0; --i){
            int count = 1;
            while(!myStack.empty() && myStack.top().first >= arr[i]){
                count += myStack.top().second;
                myStack.pop();
            }
            myStack.push({arr[i], count});
            right[i] = count;
        }
        long long res = 0;
        for(int i = 0; i < n; ++i) res += (left[i] * right[i] * (long)arr[i]);
        return res % MOD;
    }
};
int main(){
    vector<int> arr = {3,1,2,4};
    Solution *S = new Solution();
    cout<<S->sumSubarrayMins(arr)<<endl;
    return 0;
}