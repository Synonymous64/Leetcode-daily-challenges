#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count = 0, maxVal = INT_MIN, n = properties.size();
        sort(properties.begin(), properties.end(), [](auto &a, auto &b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
        for(int i = n - 1; i >= 0; --i){
            if(properties[i][1] < maxVal) count++;
            if(properties[i][1] > maxVal) maxVal = properties[i][1];
        }
        return count;
    }
};
int main(){
    vector<vector<int>> properties = {{7,9},{10,7},{6,9},{10,4},{7,5},{7,10}};
    Solution s;
    cout<<s.numberOfWeakCharacters(properties)<<endl;
    return 0;
}