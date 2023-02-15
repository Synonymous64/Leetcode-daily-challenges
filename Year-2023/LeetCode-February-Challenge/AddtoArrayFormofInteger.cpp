#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int i = num.size() - 1; i >= 0; --i){
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10;
        }
        while(k > 0){
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        return num;
    }
};
int main(){
    vector<int> num = {2,7,4}; int k = 181;
    Solution *s = new Solution();
    vector<int> res = s->addToArrayForm(num, k);
    for(auto x: res) cout<<x<<" ";
    return 0;
}