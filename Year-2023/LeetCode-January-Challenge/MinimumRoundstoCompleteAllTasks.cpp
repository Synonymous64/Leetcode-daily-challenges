#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int res = 0;
        unordered_map<int, int> mp;
        for(auto x: tasks) mp[x]++;
        for(auto x: mp){
            if(x.second <= 1) return -1;
            else if(x.second == 2) res++;
            else res += (ceil((double)x.second/3));
        }
        return res;
    }
};
int main(){
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    Solution *s = new Solution();
    cout<<s->minimumRounds(tasks)<<endl;
    return 0;
}