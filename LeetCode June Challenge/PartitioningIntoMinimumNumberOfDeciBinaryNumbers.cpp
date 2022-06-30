#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};
int main(){
    Solution s;
    string n = "82734";
    cout<<s.minPartitions(n)<<endl;
    return 0;
}