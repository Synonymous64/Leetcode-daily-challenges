#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void mergee(vector<pair<int,int>> &v, vector<int> &count, int low, int mid, int high){
        int i = low, j = mid + 1, k = 0;
        vector<pair<int,int>> temp(high - low + 1);
        while(i <= mid && j <= high){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            } else{
                count[v[i].second] += high - j + 1;
                temp[k++] = v[i++];
            }
        }
        while(i <= mid) temp[k++] = v[i++];
        while(j <= high) temp[k++] = v[j++];
        for(int i = low; i <= high; ++i) v[i] = temp[i - low];
    }
    void mergeSort(vector<pair<int,int>> &v, vector<int> &count, int low, int high){
        if(low < high){
            int mid = low + (high - low)/2;
            mergeSort(v, count, low, mid);
            mergeSort(v, count, mid + 1, high);
            mergee(v, count, low, mid, high);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; ++i){
            pair<int,int> p = make_pair(nums[i], i);
            v[i] = p;
        }
        vector<int> count(n, 0);
        mergeSort(v, count, 0, n - 1);
        return count;
    }
};
int main(){
    vector<int> nums = {5,2,6,1};
    Solution s;
    vector<int> ans = s.countSmaller(nums);
    for(int i = 0; i < ans.size(); ++i) cout<<ans[i]<<" ";
    return 0;

}