#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(j >= 0){
            if(i>= 0 && nums1[i] > nums2[j])  nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        int g = m + n;
        for(int i = 0; i < g; ++i){
            cout<<nums1[i]<<" ";
        }
    }
};
int main(){
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,5,6};
    Solution s;
    s.merge(nums1, nums1.size(), nums2, nums2.size());
    return 0; 
}