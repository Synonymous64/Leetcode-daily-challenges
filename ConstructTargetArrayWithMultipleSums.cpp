#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0, max = 0;
        for(int i = 0; i < target.size(); ++i){
            sum += target[i];
            if(target[max] < target[i]){
                max = i;
            }
        }
        long long diff = sum - target[max];
        if(diff == 1 || target[max] == 1) return true;
        if(diff > target[max] || diff == 0 || target[max] % diff == 0) return false;
        target[max] %= diff;
        return isPossible(target);
    }
};
int main(){
    vector<int> target = {9,3,5};
    Solution s;
    cout<<boolalpha<<s.isPossible(target)<<endl;
    return 0;
}