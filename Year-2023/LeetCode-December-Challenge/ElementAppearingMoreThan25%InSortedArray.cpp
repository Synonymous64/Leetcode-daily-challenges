#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();

        for(auto x: arr){
            if(++mp[x] > n / 4) return x;
        }

        return -1;
    }
};

int main(){
    vector<int> arr = {1,2,2,6,6,6,6,7,10};
    Solution *s = new Solution();
    cout<<s->findSpecialInteger(arr)<<endl;
    return 0;
}