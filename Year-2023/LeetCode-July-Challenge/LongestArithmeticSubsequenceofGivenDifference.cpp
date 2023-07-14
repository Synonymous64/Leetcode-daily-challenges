#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mp;
        int res = 1;

        for(auto x: arr){
            if(mp.count(x - difference))
                mp[x] = mp[x - difference] + 1;
            else mp[x] = 1;
            res = max(res, mp[x]);
        }
        return res;
    }
};

int main(){
    vector<int> arr = {1,2,3,4}; int difference = 1;
    Solution *s = new Solution();
    cout<<s->longestSubsequence(arr, difference)<<endl;
    return 0;
}