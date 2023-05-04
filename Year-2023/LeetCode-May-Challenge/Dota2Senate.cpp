#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;
        for(int i = 0; i < n; ++i){
            if(senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        if(radiant.empty()) return "Dire";
        if(dire.empty()) return "Radiant";
        while(!radiant.empty() && !dire.empty()){
            if(radiant.front() < dire.front()){
                dire.pop();
                int rad = radiant.front();
                radiant.pop();
                radiant.push(n + rad);
            } else{
                radiant.pop();
                int dir = dire.front();
                dire.pop();
                dire.push(n + dir);
            }
        }
        return radiant.empty() ? "Dire": "Radiant";
    }
};

int main(){
    string senate = "RD";
    Solution *s = new Solution();
    cout<<s->predictPartyVictory(senate)<<endl;
    return 0;
}