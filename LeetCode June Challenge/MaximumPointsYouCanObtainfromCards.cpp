#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, maxSum = 0, n = cardPoints.size();
        for(int i = 0; i < k; ++i){
            sum += cardPoints[i];
        }
        maxSum = sum;
        for(int i = k - 1; i >= 0; --i){
            sum -= cardPoints[i];
            sum += cardPoints[n - k + i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
int main(){
    Solution s;
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<s.maxScore(cardPoints, k)<<endl;
    return 0;
}