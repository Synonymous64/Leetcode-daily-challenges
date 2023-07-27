#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool validate(long long time, vector<int> &batteries, int n){
        long long total = 0;
        for(auto x: batteries)
            total += min(time, 1LL * x);

        return total >= time * n;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 1, high = 0;
        for(auto x: batteries) high += x;

        long long res = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(validate(mid, batteries, n)){
                low = mid + 1;
                res = mid;
            } else high = mid - 1;
        }
        return res;
    }
};

int main(){
    int n = 2; vector<int> batteries = {3,3,3};
    Solution *s = new Solution();
    cout<<s->maxRunTime(n, batteries)<<endl;
    return 0;
}