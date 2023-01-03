#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for(int col = 0; col < strs[0].size(); ++col){
            for(int row = 1; row < strs.size(); ++row){
                if(strs[row - 1][col] > strs[row][col]){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
int main(){
    vector<string> strs = strs = {"cba","daf","ghi"};
    Solution *s = new Solution();
    cout<<s->minDeletionSize(strs)<<endl;
    return 0;
}