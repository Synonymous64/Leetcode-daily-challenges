#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b){
            int bitsA = __builtin_popcount(a), bitsB = __builtin_popcount(b);
            return bitsA == bitsB ? a < b: bitsA < bitsB;});
        return arr;
    }
};

int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    Solution *s = new Solution();
    vector<int> res = s->sortByBits(arr);
    for(auto ch: arr) cout<<ch<<" ";
    return 0;
}