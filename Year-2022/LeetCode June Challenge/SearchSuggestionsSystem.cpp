#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int n = products.size(), start = 0, end = n - 1;
        for(int i = 0; i < searchWord.size(); ++i){
            while(start <= end && (i >= products[start].size() || products[start][i] < searchWord[i])) ++start;
            while(start <= end && (i >= products[end].size() || products[end][i] > searchWord[i])) --end;
            ans.push_back({});
            for(int j = start; j < min(start + 3, end + 1); ++j){
                ans.back().push_back(products[j]);
            }
        }
        return ans;
    }
    void printCode(vector<string> &nums){
        for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    }
};
int main(){
    vector<string> products = {"havana"};
    string searchWord = "havana";
    Solution s;
    vector<vector<string>> ans = s.suggestedProducts(products, searchWord);
    for(int i = 0; i < ans.size(); ++i){
        s.printCode(ans[i]);
    }cout<<endl;
    return 0;
}
