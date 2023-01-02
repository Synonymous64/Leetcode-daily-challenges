#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool helper(vector<int> &matchsticks, int target, vector<int> &sides, int index){
        if(index == matchsticks.size()){
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]) return true;
            return false;
        }
        for(int i = 0; i < 4; ++i){
            if(sides[i] + matchsticks[index] > target) continue;
            int j = i - 1;
            while(j >= 0){
                if(sides[j] == sides[i]) break;
                j--;
            }
            if(j != -1) continue;
            sides[i] += matchsticks[index];
            if(helper(matchsticks, target, sides, index + 1)) return true;
            sides[i] -= matchsticks[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.empty()) return false;
        vector<int> sides(4, 0);
        int sum = 0;
        for(int i = 0; i < matchsticks.size(); ++i) sum += matchsticks[i];
        int target = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), [](auto &a, auto &b){return a > b;});
        if(matchsticks[0] > target) return false;
        return helper(matchsticks, target, sides, 0);
    }
};
int main(){
    vector<int> matchsticks = {1,1,2,2,2};
    Solution s;
    cout<<boolalpha<<s.makesquare(matchsticks)<<endl;
    return 0;
}