#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0; int minVal = INT_MAX, maxVal = INT_MIN;
        for(auto x: salary){
            sum += x;
            minVal = min(minVal, x);
            maxVal = max(maxVal, x);
        }
        sum -= (minVal + maxVal);
        return sum / (salary.size() - 2);
    }
};

int main(){
    vector<int> salary = {4000,3000,1000,2000};
    Solution *s = new Solution();
    cout<<s->average(salary)<<endl;
    return 0;
}