#include<bits/stdc++.h>
using namespace std;
static int MOD = 1e9 + 7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, long long int> mp; int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; ++i){
            mp.insert({arr[i], 1});
        }
        for(int i = 1; i < n; ++i){
            auto it3 = mp.find(arr[i]);
            long long int count = 0;
            for(int j = 0; j < i; ++j){
                if(arr[i] % arr[j] == 0){
                    auto it = mp.find(arr[i]/arr[j]);
                    auto it2 = mp.find(arr[j]);
                    if(it != mp.end()){
                        count += (it->second * it2->second);
                    }
                }
            }
            it3->second += count;
        }
        long long int res = 0;
        for(auto parts : mp){
            res += parts.second;
        }
        return res % MOD;
    }
};
int main(){
    vector<int> arr = {2,4};
    Solution s;
    cout<<s.numFactoredBinaryTrees(arr)<<endl;
    return 0;
}