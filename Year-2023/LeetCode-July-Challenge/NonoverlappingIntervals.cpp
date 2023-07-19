#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        int res = -1;

        for(auto x: intervals){
            if(x[0] < prev[1] && x[1] <= prev[1]){
                prev = x;
                res++;
            } else if(x[0] < prev[1] && x[1] > prev[1]) res++;
            else prev = x;
        }

        return res;
    }
};

int main(){
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    Solution *s = new Solution();
    cout<<s->eraseOverlapIntervals(intervals)<<endl;
    return 0;
}