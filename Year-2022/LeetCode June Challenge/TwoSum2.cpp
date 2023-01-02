#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum1(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while(numbers[start] + numbers[end] != target){
            if(numbers[start] + numbers[end] < target) start++;
            else end--;
        }
        return {start + 1, end + 1};
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while(start <= end){
            if(numbers[start] + numbers[end] == target)
                return {start + 1, end + 1};
            else if(numbers[start] + numbers[end] < target)
                start++;
            else end--;
        }
        return {};
    }
};
int main(){
    vector<int> numbers = {1,2,3,4,4,9,56,90};
    int target = 8;
    Solution s;
    vector<int> ans = s.twoSum(numbers, target);
    for(int i = 0; i < ans.size(); ++i) cout<<ans[i]<<" ";
    return 0;
}