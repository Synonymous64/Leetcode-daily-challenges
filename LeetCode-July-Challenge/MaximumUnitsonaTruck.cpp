#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b){return a[1] > b[1];});
        int ans = 0, nBoxes = 0, takenBoxes = 0, i = 0;
        for(i = 0; i < boxTypes.size(); ++i){
            nBoxes += boxTypes[i][0];
            if(nBoxes <= truckSize){
                takenBoxes += boxTypes[i][0];
                ans += boxTypes[i][0] * boxTypes[i][1];
            } else break;
        }
        if(takenBoxes < truckSize && i < boxTypes.size()){
            ans += (truckSize - takenBoxes) * boxTypes[i][1];
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> boxTypes = {{1,3},{2,2},{3,1}};
    int truckSize = 4;
    Solution s;
    cout<<s.maximumUnits(boxTypes, truckSize)<<endl;
    return 0;
}