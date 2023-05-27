#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> score(stoneValue.size(), 0);
        for(int i = score.size() - 1; i >= 0; --i){
            int take = 0;
            int best = INT_MIN;
            for(int j = 0; j < 3 && i + j < stoneValue.size(); ++j){
                take += stoneValue[i + j];
                int opponent = (i + j + 1 < stoneValue.size()) ? score[i + j + 1]: 0;
                best = max(best, take - opponent);
            }
            score[i] = best;
        }
        return score[0] > 0 ? "Alice" : score[0] == 0 ? "Tie" : "Bob";
    }
};

int main(){
    vector<int> values = {1,2,3,7};
    Solution *s = new Solution();
    cout<<s->stoneGameIII(values)<<endl;
    return 0;
}