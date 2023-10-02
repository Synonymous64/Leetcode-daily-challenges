#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceCount = 0, bobCount = 0;
        for(int i = 1; i < colors.size() - 1; ++i){
            if(colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') aliceCount++;
            if(colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B') bobCount++;
        }
        return aliceCount > bobCount;
    }
};

int main(){
    Solution *s = new Solution();
    string colors = "AAABABB";
    cout<<boolalpha<<s->winnerOfGame(colors)<<endl;
    return 0;
}