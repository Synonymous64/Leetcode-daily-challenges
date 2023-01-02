#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto ch: arr) mp[ch]++;
        unordered_set<int> ms;
        for(auto ele: mp) ms.insert(ele.second);
        return mp.size() == ms.size();
    }
};
int main(){
    vector<int> arr = {1,2,2,1,1,3};
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->uniqueOccurrences(arr)<<endl;
    return 0;
}