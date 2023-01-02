#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool DFS(int idx, int row, int col, vector<vector<char>> &board, string word){
        if(idx == word.size()) return true;
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false;
        bool res = false;
        if(word[idx] == board[row][col]){
            board[row][col] = '.';
            res = DFS(idx + 1, row + 1, col, board, word) || DFS(idx + 1, row - 1, col, board, word) || DFS(idx + 1, row, col + 1, board, word) || DFS(idx + 1, row, col - 1, board, word);
            board[row][col] = word[idx];
        }
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        int idx = 0;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(word[idx] == board[row][col]){
                    if(DFS(idx, row, col, board, word)) return true;
                }
            }
        }
        return false;
    }
};
int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution *S = new Solution();
    cout<<std::boolalpha<<S->exist(board, word)<<endl;
    return 0;
}