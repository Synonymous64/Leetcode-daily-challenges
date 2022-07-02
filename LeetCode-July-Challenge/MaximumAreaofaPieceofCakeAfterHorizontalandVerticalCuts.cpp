#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const long mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long maxHorDiff = 0, maxVerDiff = 0;
        for(int i = 1; i < horizontalCuts.size(); ++i){
            if(maxHorDiff < horizontalCuts[i] - horizontalCuts[i - 1]){
                maxHorDiff = horizontalCuts[i] - horizontalCuts[i - 1];
            }
        }
        for(int i = 1; i < verticalCuts.size(); ++i){
            if(maxVerDiff < verticalCuts[i] - verticalCuts[i - 1]){
                maxVerDiff = verticalCuts[i] - verticalCuts[i - 1];
            }
        }
        long ans = maxVerDiff * maxHorDiff;
        return ans % mod;
    }
};
int main(){
    int h = 5, w = 4;
    vector<int> horizontalCuts = {1,2,4}, verticalCuts = {1,3};
    Solution s;
    cout<<s.maxArea(h, w, horizontalCuts, verticalCuts);
    return 0;
}