#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 2; i <= n; ++i){
            string lastString = res;
            int start = 0;
            int end = res.size();
            res = "";
            while(start < end){
                int count = start;
                while(start < end && lastString[start] == lastString[count]) ++count;
                res += to_string(count - start) + lastString[start];
                start = count;
            }
        }
        return res;
    }
};
int main(){
    int n = 4;
    Solution s;
    cout<<s.countAndSay(n)<<endl;
    return 0;
}