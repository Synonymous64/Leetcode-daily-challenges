#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(auto i : arr) freq[i]++;
        multimap<int,int, greater<int>> mm;
        for(auto i : freq) mm.insert({i.second, i.first});
        int n = arr.size(), sum = n, count = 0;
        for(auto it = mm.begin(); it != mm.end(); ++it){
            sum -= it->first;
            count++;
            if(sum <= n/2) return count;
        }
        return count;
    }
};
int main(){
    vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
    Solution s;
    cout<<s.minSetSize(arr)<<endl;
    return 0;
}