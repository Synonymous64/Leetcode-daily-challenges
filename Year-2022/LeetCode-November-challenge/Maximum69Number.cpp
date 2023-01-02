#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximum69Number (int num) {
        string res = to_string(num);
        for(auto &x: res){
            if(x == '6'){
                x = '9';
                break;
            }
        }
        return stoi(res);
    }
};
int main(){
    int num = 9669;
    Solution s;
    cout<<s.maximum69Number(num)<<endl;
    return 0;
}