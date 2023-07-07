#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int F = 0, T = 0, res = 0, curr = 0;
        for(int i = 0; i < answerKey.size(); ++i){
            if(answerKey[i] == 'T') T++;
            else F++;
            if(min(T, F) > k){
                if(answerKey[curr] == 'T')T--;
                else F--;
                curr++;
            }
            res = max(res, T + F);
        }
        return res;
    }
};

int main(){
    string answerKey = "TTFF"; int k = 2;
    Solution *s = new Solution();
    cout<<s->maxConsecutiveAnswers(answerKey, k)<<endl;
    return 0;
}