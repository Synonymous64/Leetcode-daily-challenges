#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end()); int i = 0, j = tokens.size() - 1, score = 0, res = 0;
        while(i <= j){
            if(tokens[i] <= power){
                score++;
                power -= tokens[i++];
                if(score > res) res = score;
            } else if(score > 0){
                score--;
                power += tokens[j--];
            } else break;
        }
        return  res;
    }
};
int main(){
    vector<int> tokens = {100};
    int power = 50;
    Solution s; cout<<s.bagOfTokensScore(tokens, power)<<endl;
    return 0;
}