import java.util.Arrays;

public class NQueens2 {
    private void totalNQueensFunct(String[] chess, String[][] ans, int row) {
        if(chess.length == 0) return;
        if(row == chess.length){
            
        }
        
    }
    public int totalNQueens(int n) {
        String s = "";
        for(int i = 0; i < n; ++i){
            s += '.';
        }
        String[][] ans;
        String[] temp = new String[]{s};
        totalNQueensFunct(temp, ans, 0);
        return ans.length;
    }
    public static void main(String[] args) {
        NQueens2 p = new NQueens2();
        int n = 4;
        System.out.println(p.totalNQueens(n));
    }
}
