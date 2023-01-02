#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isSafe(vector<string> &chess, int cols, int rows){
        for(int i = 0; i < rows; ++i){
            if(chess[i][cols] == 'Q') return false;
        }
        for(int i = rows - 1, j = cols - 1; i >= 0 && j >= 0; --i,--j){
            if(chess[i][j] == 'Q') return false;
        }
        for(int i = rows - 1, j = cols + 1; i >= 0 && j < chess[0].size(); --i, ++j){
            if(chess[i][j] == 'Q') return false;
        }
        return true;
    }
    void totalNQueensFunct(vector<string> &chess, vector<vector<string>> &ans, int row) {
        if(chess.empty()) return;
        if(row == chess.size()){
            ans.push_back(chess);
            return;
        }
        for(int i = 0; i < chess[0].size(); ++i){
            if(isSafe(chess, i, row)){
                chess[row][i] = 'Q';
                totalNQueensFunct(chess, ans, row + 1);
                chess[row][i] = '.';
            }
        }
    }

public:
    int totalNQueens(int n) {
        string s = "";
        for(int i = 0; i < n; ++i){
            s += '.';
        }
        vector<vector<string>> ans;
        vector<string> temp(n, s);
        totalNQueensFunct(temp, ans, 0);
        return ans.size();
    }
};
int main(){
    int n = 4;
    Solution s;
    cout<<s.totalNQueens(n)<<endl;
    return 0;
}