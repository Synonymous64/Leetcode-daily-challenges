#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dp[101][201];
    int mod = 1e9 + 7;
    int helper(vector<int> &locations, int idx, int finish, int fuel){
        if(fuel <= 0) return idx == finish ? 1: 0;
        if(dp[idx][fuel] != -1) return dp[idx][fuel];

        int res = 0;
        if(idx == finish) res = 1;

        for(int i = 0; i < locations.size(); ++i){
            if(i != idx && abs(locations[idx] - locations[i]) <= fuel){
                res = (res % mod + helper(locations, i, finish, fuel - abs(locations[idx] - locations[i])) % mod) % mod;
            }
        }
        return dp[idx][fuel] = res % mod;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return helper(locations, start, finish, fuel);
    }
};

int main(){
    vector<int> locations = {2,3,6,8,4}; int start = 1, finish = 3, fuel = 5;
    Solution *s = new Solution();
    cout<<s->countRoutes(locations, start, finish, fuel)<<endl;
    return 0;
}