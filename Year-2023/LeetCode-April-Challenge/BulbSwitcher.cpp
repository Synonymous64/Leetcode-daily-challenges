#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main(){
    int n = 1;
    Solution *s = new Solution();
    cout<<s->bulbSwitch(n)<<endl;
    return 0;
}