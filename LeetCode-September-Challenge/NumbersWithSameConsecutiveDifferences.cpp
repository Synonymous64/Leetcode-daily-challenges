#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void DFS(int n, int k, int curr, int i, int prev, vector<int> &res){
        if(i == n - 1){
            res.push_back(curr);
            return;
        }
        int next = prev + k;
        if(next < 10) DFS(n, k, (curr * 10) + next, i + 1, next, res);
        next = prev - k;
        if(k != 0 && next >= 0) DFS(n, k, (curr * 10) + next, i + 1, next, res);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> res;
        for(int i = 1; i <= 9; ++i) DFS(n, k, i, 0, i, res);
        return res;
    }
};
int main(){
    int n = 3, k= 7;
    Solution s;
    vector<int> res = s.numsSameConsecDiff(n, k);
    for(int i = 0; i < res.size(); ++i) cout<<res[i]<<" ";
    return 0;
}