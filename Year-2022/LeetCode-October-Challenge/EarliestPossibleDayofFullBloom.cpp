#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> days; int start = 0, res = 0;
        for(int i = 0; i < plantTime.size(); ++i) days.push_back({plantTime[i], growTime[i]});
        sort(days.begin(), days.end(), [](auto &a, auto &b){ return a.second > b.second;});
        for(auto x: days){
            start += x.first;
            res = max(res, start + x.second);
        }
        return res;
    }
};
int main(){
    vector<int> plantTime = {1,4,3}, growTime = {2,3,1};
    Solution s;
    cout<<s.earliestFullBloom(plantTime, growTime)<<endl;
    return 0;
}