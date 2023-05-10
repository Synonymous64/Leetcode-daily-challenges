#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startRow = 0, endRow = n - 1;
        int startCol = 0, endCol = n - 1;
        int total = n * n, counter = 1;
        vector<vector<int>> res(n, vector<int>(n, 1));
        while(counter <= total){
            for(int i = startCol; i <= endCol && counter <= total; ++i)
                res[startRow][i] = counter++;
            startRow++;
            for(int i = startRow; i <= endRow && counter <= total; ++i)
                res[i][endCol] = counter++;
            endCol--;
            for(int i = endCol; i >= startCol && counter <= total; --i)
                res[endRow][i] = counter++;
            endRow--;
            for(int i = endRow; i >= startRow && counter <= total; --i)
                res[i][startCol] = counter++;
            startCol++;
        }
        return res;
    }
};

int main(){
    int n = 3;
    Solution *s = new Solution();
    vector<vector<int>> res = s->generateMatrix(n);
    for(auto arr: res)
        for(auto x: arr) cout<<x<<" ";
    return 0;
}