#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < groupSizes.size(); ++i){
            int key = groupSizes[i];
            mp[key].push_back(i);
            if(mp[key].size() == key){
                res.push_back(mp[key]);
                mp.erase(key);
            }
        }
        return res;
    }
};

int main(){
    vector<int> groupSizes = {3,3,3,3,3,1,3};
    Solution *s = new Solution();
    vector<vector<int>> res = s->groupThePeople(groupSizes);
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[0].size(); ++j){
            cout<<res[i][j]<<" ";
        }
    }
    return 0;
}