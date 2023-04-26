#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int sum = 0;
            while(num){
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};
int main(){
    int num = 38;
    Solution *s = new Solution();
    cout<<s->addDigits(num)<<endl;
    return 0;
}