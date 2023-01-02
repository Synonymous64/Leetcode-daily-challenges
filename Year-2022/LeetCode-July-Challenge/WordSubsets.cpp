#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool subsets(int *arr, int *target){
        for(int i = 0; i < 26; ++i){
            if(target[i] > arr[i]) return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        int target[26] = {0};
        for(auto a : words2){
            int temp[26] = {0};
            for(auto b : a){
                temp[b - 'a']++;
                target[b - 'a'] = max(target[b - 'a'], temp[b - 'a']);
            }
        }
        for(auto a : words1){
            int temp[26] = {0};
            for(auto b : a){
                temp[b - 'a']++;
            }
            if(subsets(temp, target)){
                res.push_back(a);
            }
        }
        return res;
    }
};
int main(){
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    Solution s;
    vector<string> res = s.wordSubsets(words1, words2);
    for(int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    }
    return 0;
}