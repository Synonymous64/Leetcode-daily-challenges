#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n & 1) return {};
        sort(changed.begin(), changed.end());
        unordered_map<int,int> Freq;
        vector<int> res;
        for(auto i : changed) Freq[i]++;
        for(auto x : changed){
            if(Freq[x] == 0) continue;
            if(Freq[x * 2] == 0) return {};
            if(Freq[x] && Freq[x * 2]){
                res.push_back(x);
                Freq[x]--, Freq[x * 2]--;
            }
        }
        return res;
    }
};
int main(){
    vector<int> changed = {1,3,4,2,6,8};
    Solution s;
    vector<int> res = s.findOriginalArray(changed);
    for(int i = 0; i < res.size(); ++i) cout<<res[i]<<" ";
    return 0;
}