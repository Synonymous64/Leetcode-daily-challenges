#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, temp = 0;
        for(auto x: gain){
            temp += x;
            res = max(res, temp);
        }
        return res;
    }
};
int main(){
    vector<int> gain = {-5,1,5,0,-7};
    Solution *s = new Solution();
    cout<<s->largestAltitude(gain)<<endl;
    return 0;
}