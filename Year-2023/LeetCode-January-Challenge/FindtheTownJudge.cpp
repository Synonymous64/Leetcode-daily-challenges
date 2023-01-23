#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0), out(n + 1, 0);
        for(auto x: trust){
            in[x[1]]++;
            out[x[0]]++;
        }
        int res = -1;
        for(int i = 1; i <= n; ++i)
            if(in[i] == n - 1 && out[i] == 0) return res = i;
        return res;
    }
};
int main(){
    int n = 2; vector<vector<int>> trust = {{1,2}};
    Solution *s = new Solution();
    cout<<s->findJudge(n, trust)<<endl;
    return 0;
}