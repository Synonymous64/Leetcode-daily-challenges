#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penality = 0;

        for(auto x: customers)
            if(x == 'N') penality++;

        int res = n;
        int mini = penality;

        for(int i = n - 1; i >= 0; --i){
            if(customers[i] == 'Y') penality++;
            else penality--;
            if(penality <= mini){
                mini = penality;
                res = i;
            }
        }
        return res;
    }
};

int main(){
    string customers = "YYNY";
    Solution *s = new Solution();
    cout<<s->bestClosingTime(customers)<<endl;
    return 0;
}