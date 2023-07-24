#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, long long int n) {
        double res = 1;
        if(n == 0 || x == 1) return 1;
        else if(n < 0){
            x = 1 / x;
            n = -n;
        }

        res *= x;
        n--;
        int t = 0;

        while(n){
            t++;
            if(t < n){
                res *= res;
                n -= t;
                t += t;
            } if(n > 0){
                res *= x;
                n--;
            }
        }
        return res;
    }
};

int main(){
    double x = 2.00000; int n = 10;
    Solution *s = new Solution();
    cout<<s->myPow(x, n)<<endl;
    return 0;
}