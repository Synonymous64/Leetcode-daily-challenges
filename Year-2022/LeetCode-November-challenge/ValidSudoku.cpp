#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> mySet;
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    string row = "row"+to_string(i)+board[i][j];
                    string col = "col"+to_string(j)+board[i][j];
                    string box = "box"+to_string((i / 3) * 3 + (j / 3))+board[i][j];
                    if(mySet.find(row) == mySet.end() && mySet.find(col) == mySet.end() && mySet.find(box) == mySet.end()){
                        mySet.insert(row);
                        mySet.insert(col);
                        mySet.insert(box);
                    } else return false;
                }
            }
        }
        return true;
    }
};
int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};
    Solution *s = new Solution();
    cout<<boolalpha<<s->isValidSudoku(board)<<endl;
    return 0;
}