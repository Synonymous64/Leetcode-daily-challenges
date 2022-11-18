#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isUgly(int n) {
        while(n > 1){
            if(n % 2 == 0) n /= 2;
            else if(n % 3 == 0) n /= 3;
            else if(n % 5 == 0) n /= 5;
            else break;
        }
        return n == 1;
    }
};
int main(){
    int n = 14;
    Solution *s = new Solution();
    cout<<boolalpha<<s->isUgly(n)<<endl;
    return 0;
}