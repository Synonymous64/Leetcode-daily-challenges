#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
int main(){
    Solution *s = new Solution();
    int low = 5, high = 7;
    cout<<s->countOdds(low, high)<<endl;
    return 0;
}