#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool findInterleave(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == s1.size() && j == s2.size() && k == s3.size()) return true;

        bool x = false, y = false;

        if(i < s1.size() && s1[i] == s3[k])
            x = findInterleave(s1, s2, s3, i + 1, j, k + 1, dp);
        if(j < s2.size() && s2[j] == s3[k])
            y = findInterleave(s1, s2, s3, i, j + 1, k + 1, dp);

        return dp[i][j] = x || y;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return findInterleave(s1, s2, s3, 0, 0, 0, dp);
    }
};

int main(){
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution *s = new Solution();
    cout<<std::boolalpha<<s->isInterleave(s1, s2, s3)<<endl;
    return 0;
}