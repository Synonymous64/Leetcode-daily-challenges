#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xDiff = abs(fx - sx), yDiff = abs(fy- sy);
        if(xDiff == 0 && yDiff == 0 && t == 1) return false;
        return min(xDiff, yDiff) + abs(xDiff - yDiff) <= t;
    }
};

int main(){
    int sx = 2, sy = 4, fx = 7, fy = 7, t = 6;
    Solution *s = new Solution();
    cout<<boolalpha<<s->isReachableAtTime(sx, sy, fx, fy, t)<<endl;
    return 0;
}