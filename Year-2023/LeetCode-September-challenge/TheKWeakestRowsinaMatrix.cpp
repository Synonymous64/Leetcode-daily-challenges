#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();

        for(int i = 0; i < mat.size(); ++i) mat[i].push_back(i);
        vector<int> res(k);

        sort(mat.begin(), mat.end());

        for(int i = 0; i < k; ++i){
            res[i] = mat[i][n];
        }
        return res;
    }
};

int main(){
    vector<vector<int>> mat = {
                    {1,1,0,0,0},
                    {1,1,1,1,0},
                    {1,0,0,0,0},
                    {1,1,0,0,0},
                    {1,1,1,1,1}
                };
    int k = 3;
    Solution *s = new Solution();
    vector<int> res = s->kWeakestRows(mat, k);
    for(auto ch: res) cout<<ch<<" ";
    return 0;
}