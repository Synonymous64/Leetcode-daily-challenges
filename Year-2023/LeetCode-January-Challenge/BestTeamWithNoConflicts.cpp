#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(vector<pair<int,int>> ageScorePairs){
        int n = ageScorePairs.size();
        vector<int> dp(n);
        int res = 0;

        for(int i = 0; i < n; ++i){
            dp[i] = ageScorePairs[i].second;
            res = max(res, dp[i]);
        }

        for(int i = 0; i < n; ++i){
            for(int j = i - 1; j >= 0; --j){
                if(ageScorePairs[i].second >= ageScorePairs[j].second){
                    dp[i] = max(dp[i], ageScorePairs[i].second + dp[j]);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> ageScorePairs;
        for(int i = 0; i < scores.size(); ++i){
            ageScorePairs.push_back({ages[i], scores[i]});
        }
        sort(ageScorePairs.begin(), ageScorePairs.end());
        return helper(ageScorePairs);
    }
};
int main(){
    vector<int> scores = {1,3,5,10,15}, ages = {1,2,3,4,5};
    Solution *s = new Solution();
    cout<<s->bestTeamScore(scores, ages)<<endl;
    return 0;
}