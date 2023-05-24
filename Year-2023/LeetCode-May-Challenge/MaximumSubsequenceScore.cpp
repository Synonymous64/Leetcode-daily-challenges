#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vec;
        for(int i = 0; i < nums1.size(); ++i)
            vec.push_back({nums2[i], nums1[i]});
        sort(vec.rbegin(), vec.rend());

        long long currSum = 0;
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < k - 1; ++i){
            currSum += vec[i].second;
            pq.push(vec[i].second);
        }

        for(int i = k - 1; i < nums1.size(); ++i){
            currSum += vec[i].second;
            pq.push(vec[i].second);
            res = max(res, currSum * vec[i].first);
            currSum -= pq.top();
            pq.pop();
        }

        return res;
    }
};

int main(){
    vector<int> nums1 = {1,3,3,2}, nums2 = {2,1,3,4}; int k = 3;
    Solution *s = new Solution();
    cout<<s->maxScore(nums1, nums2, k)<<endl;
    return 0;
}