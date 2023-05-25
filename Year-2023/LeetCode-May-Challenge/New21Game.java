class Solution {
    public double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts) return 1.0;
        double[] dp = new double[n + 1];
        dp[0] = 1.0;

        double sum = 1.0, res = 0.0;
        for(int i = 1; i <= n; ++i){
            dp[i] = sum / maxPts;
            if(i < k) sum += dp[i];
            else res += dp[i];
            if(i >= maxPts) sum -= dp[i - maxPts];
        }
        return res;
    }
}
public class New21Game{
    public static void main(String[] args) {
        int n = 10, k = 1, maxPts = 10;
        System.out.println(new Solution().new21Game(n, k, maxPts));
    }
}