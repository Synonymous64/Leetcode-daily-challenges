#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int DFS(vector<vector<int>> &children, string &s, int &res ,int i){
        int big1 = 0, big2 = 0;
        for(auto &x: children[i]){
            int curr = DFS(children, s, res, x);
            if(s[i] == s[x]) continue;
            if(curr > big2)  big2 = curr;
            if(big2 > big1) swap(big1, big2);
        }
        res = max(res, big1 + big2 + 1);
        return big1 + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size(); int res = 0;
        vector<vector<int>> children(n, vector<int>());
        for(int i = 1; i < n; ++i) children[parent[i]].push_back(i);
        DFS(children, s, res, 0);
        return res;
    }
};
int main(){
    vector<int> parent = {-1,0,0,1,1,2}; string s = "abacbe";
    Solution *S = new Solution();
    cout<<S->longestPath(parent, s)<<endl;
    return 0;
}