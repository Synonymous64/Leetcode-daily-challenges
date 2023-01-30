import java.util.*;

class Solution {
    private int dp[] = new int[38];
    private int helper(int n){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(n - 1) + helper(n - 2) + helper(n - 3);
    }
    public int tribonacci(int n) {
        Arrays.fill(dp, -1);
        return helper(n);
    }
}
public class NthTribonacciNumber {
    public static void main(String[] args) {
        int n = 25;
        Solution s = new Solution();
        System.out.println(s.tribonacci(n));
    }
}
