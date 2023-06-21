#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    long long f(vector<int>& A, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
            res += 1L * abs(A[i] - x) * cost[i];
        return res;
    }
public:
    long long minCost(vector<int>& A, vector<int>& cost) {
        long long l = 1, r = 1000000, res = f(A, cost, 1), x;
        while (l < r) {
            x = (l + r) / 2;
            long long y1 = f(A, cost, x), y2 = f(A, cost, x + 1);
            res = min(y1, y2);
            if (y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return res;
    }

};

int main(){
    vector<int> nums = {1,3,5,2}, cost = {2,3,1,14};
    Solution *s = new Solution();
    cout<<s->minCost(nums, cost)<<endl;
    return 0;
}