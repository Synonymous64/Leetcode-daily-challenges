#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> m, m1;
        for(auto i : nums) m[i]++;
        for(auto i : nums){
            if(m[i] == 0) continue;
            m[i]--;
            if(m1[i - 1] > 0){
                m1[i - 1]--;
                m1[i]++;
            } else if(m[i + 1] != 0 && m[i + 2] != 0){
                m[i + 1]--;
                m[i + 2]--;
                m1[i + 2]++;
            } else return false;
        }
        return true;
    }
};
int main(){
    vector<int> nums = {1,2,3,4,4,5};
    Solution s;
    cout<<std::boolalpha<<s.isPossible(nums)<<endl;
    return 0;
}