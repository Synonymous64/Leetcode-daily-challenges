#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    string buildString(vector<int> &nums){
        string res = "";
        for(auto x: nums){
            res += to_string(x);
            res += ":";
        }
        return res;
    }
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mp;
        for(auto x: grid){
            mp[buildString(x)]++;
        }

        int res = 0;
        for(int col = 0; col < grid[0].size(); ++col){
            string store = "";
            for(int row = 0; row < grid.size(); ++row){
                store += to_string(grid[row][col]);
                store += ":";
            }
            res += mp[store];
        }
        return res;
    }
};

int main(){
    vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
    Solution *s = new Solution();
    cout<<s->equalPairs(grid)<<endl;
    return 0;
}