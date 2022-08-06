#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets)/log(minutesToTest/minutesToDie + 1));
    }
};
int main(){
    int buckets = 1000, minutesToDie = 15, minutesToTest = 60;
    Solution s;
    cout<<s.poorPigs(buckets, minutesToDie, minutesToTest)<<endl;
    return 0;
}