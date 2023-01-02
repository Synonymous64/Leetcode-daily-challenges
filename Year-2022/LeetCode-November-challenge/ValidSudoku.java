import java.util.*;
class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<String> mySet = new HashSet<>();
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    String row = "row"+ ' ' * i + board[i][j];
                    String col = "col"+ ' ' * j + board[i][j];
                    String box = "box" + ' ' * ((i / 3) * 3 + ( j / 3)) + board[i][j];
                    if(!mySet.contains(row) && !mySet.contains(col) && !mySet.contains(box)){
                        mySet.add(row);
                        mySet.add(col);
                        mySet.add(box);
                    } else return false;
                }
            }
        }
        return true;
    }
}
public class ValidSudoku{
    public static void main(String[] args) {
        char[][] board = {{'5','3','.','.','7','.','.','.','.'}
                        ,{'6','.','.','1','9','5','.','.','.'}
                        ,{'.','9','8','.','.','.','.','6','.'}
                        ,{'8','.','.','.','6','.','.','.','3'}
                        ,{'4','.','.','8','.','3','.','.','1'}
                        ,{'7','.','.','.','2','.','.','.','6'}
                        ,{'.','6','.','.','.','.','2','8','.'}
                        ,{'.','.','.','4','1','9','.','.','5'}
                        ,{'.','.','.','.','8','.','.','7','9'}};
        Solution s = new Solution();
        System.out.println(s.isValidSudoku(board));
    }
}