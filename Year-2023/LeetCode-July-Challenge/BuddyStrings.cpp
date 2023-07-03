#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;

        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); ++i)
            mp[s[i]] = i;

        for(int i = 0; i < goal.size(); ++i){
            if(mp.find(goal[i]) == mp.end()) return false;

            if(mp[goal[i]] != i){
                swap(s[i], s[mp[goal[i]]]);
                if(s == goal) return true;
                swap(s[i], s[mp[goal[i]]]);
            }
        }
        return false;
    }
};

int main(){
    string s = "ab", goal = "ba";
    Solution *S = new Solution();
    cout<<std::boolalpha<<S->buddyStrings(s, goal)<<endl;
    return 0;
}