class Solution {
    public int numSquares(int n) {
        if(Math.ceil(Math.sqrt(n)) == Math.floor(Math.sqrt(n))) return 1;
        while(n % 4 == 0) n /= 4;
        if(n % 8 == 7) return 4;
        for(int i = 0; i * i <= n; ++i){
            int base = (int)Math.sqrt(n - i * i);
            if(base * base == (n - i * i)) return 2;
        }
        return 3;
    }
}
public class PerfectSquares {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.numSquares(41));
    }
}
