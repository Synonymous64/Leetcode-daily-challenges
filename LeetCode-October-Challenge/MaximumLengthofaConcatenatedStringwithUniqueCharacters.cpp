#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int index, string temp, vector<string> &arr){
        unordered_set<char> mySet(temp.begin(), temp.end());
        if(temp.size() != mySet.size()) return 0;
        int res = temp.size();
        for(int i = index; i < arr.size(); ++i) res = max(res, helper(i + 1, temp + arr[i], arr));
        return res;
    }
public:
    int maxLength(vector<string>& arr) {
        return helper(0, "", arr);
    }
};
int main(){
    vector<string> arr = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"};
    Solution s;
    cout<<s.maxLength(arr)<<endl;
    return 0;
}