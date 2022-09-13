#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int nextByte = 0;
        for(auto x : data){
            if(nextByte == 0){
                if((x >> 5 == 0b110)) nextByte = 1;
                else if((x >> 4) == 0b1110) nextByte = 2;
                else if((x >> 3) == 0b11110) nextByte = 3;
                else if((x >> 7) != 0b0) return false;
            } else {
                if((x >> 6) != 0b10) return false;
                nextByte--;
            }
        }
        return nextByte == 0;
    }
};
int main(){
    vector<int> data = {197,130,1};
    Solution s;
    cout<<std::boolalpha<<s.validUtf8(data)<<endl;
    return 0;
}