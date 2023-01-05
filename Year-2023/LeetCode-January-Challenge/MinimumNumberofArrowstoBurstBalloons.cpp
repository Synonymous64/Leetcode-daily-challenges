#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end(), [](auto &a, auto &b){ return a[1] < b[1];});
        int arrows = 1, last = points[0][1];
        for(int i = 1; i < points.size(); ++i){
            if(points[i][0] > last){
                arrows++;
                last = points[i][1];
            }
        }
        return arrows;
    }
};
int main(){
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    Solution *s = new Solution();
    cout<<s->findMinArrowShots(points)<<endl;
    return 0;
}