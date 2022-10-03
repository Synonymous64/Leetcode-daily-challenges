#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, j = 0, n = colors.size(), totalTime = 0;
        while(i < n && j < n){
            int currTime = 0, maxTime = 0;
            while(j < n && colors[i] == colors[j]){
                maxTime = max(maxTime, neededTime[j]);
                currTime += neededTime[j];
                ++j;
            }
            i = j;
            totalTime += (currTime - maxTime);
        }
        return totalTime;
    }
};
int main(){
    string colors = "aaabbbabbbb";
    vector<int> neededTime = {3,5,10,7,5,3,5,5,4,8,1};
    Solution s;
    cout<<s.minCost(colors, neededTime)<<endl;
    return 0;
}