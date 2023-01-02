#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> imag1, imag2;
        int n = img1.size(), res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(img1[i][j] == 1) imag1.push_back({i, j});
                if(img2[i][j] == 1) imag2.push_back({i, j});
            }
        }
        map<pair<int,int>, int> mp;
        for(auto p: imag1){
            for(auto q: imag2){
                mp[{p.first - q.first, p.second - q.second}]++;
                res = max(res, mp[{p.first - q.first, p.second - q.second}]);
            }
        }
        return res;
    }
};
int main(){
    vector<vector<int>> img1 = {{1,1,0},{0,1,0},{0,1,0}}, img2 = {{0,0,0},{0,1,1},{0,0,1}};
    Solution s;
    cout<<s.largestOverlap(img1, img2)<<endl;
    return 0;
}