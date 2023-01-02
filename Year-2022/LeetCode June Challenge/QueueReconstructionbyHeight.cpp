#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto &a, auto &b){return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];});
        vector<vector<int>> ans;
        for(auto p : people){
            ans.insert(ans.begin() + p[1], p);
        }      
        return ans;
    }
    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i){
            cout<<nums[i]<<" ";
        }
    }
};
int main(){
    vector<vector<int>> people = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    Solution s;
    vector<vector<int>> ans = s.reconstructQueue(people);
    for(int i = 0; i < ans.size(); ++i){
        s.printCode(ans[i]);
    }
    return 0;
}