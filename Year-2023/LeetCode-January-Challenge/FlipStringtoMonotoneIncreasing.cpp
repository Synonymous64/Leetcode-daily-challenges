#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int minFlips = 0, counter = 0;
        for(auto ch: s){
            if(ch == '1') counter++;
            else minFlips++;
            minFlips = min(minFlips, counter);
        }
        return minFlips;
    }
};
int main(){
    string s = "00110";
    Solution *S = new Solution();
    cout<<S->minFlipsMonoIncr(s)<<endl;
    return 0;
}