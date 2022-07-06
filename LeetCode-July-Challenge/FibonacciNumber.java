import java.util.Arrays;

class Solution {
    int[] dp = new int[54];
    public int fib(int n) {
        Arrays.fill(dp, -1);
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
}
public class FibonacciNumber {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.fib(3));
    }
}