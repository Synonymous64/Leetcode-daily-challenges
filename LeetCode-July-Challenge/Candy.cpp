#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), totalCandies = 0;
        if(n <= 1) return 1;
        vector<int> candies(n, 1);
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; --i){
            if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]){
                candies[i] = candies[i + 1] + 1;
            }
        }
        for(int i = 0; i < candies.size(); ++i){
            totalCandies += candies[i];
        }
        return totalCandies;
    }
};
int main(){
    vector<int> ratings = {1,0,2};
    Solution s;
    cout<<s.candy(ratings)<<endl;
    return 0 ;
}