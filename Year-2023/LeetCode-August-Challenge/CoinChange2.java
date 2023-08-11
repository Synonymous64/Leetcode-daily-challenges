class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];

        dp[0] = 1;

        for (int x : coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i - x >= 0) {
                    dp[i] += dp[i - x];
                }
            }
        }

        return dp[amount];
    }
}

public class CoinChange2 {
    public static void main(String[] args) {
        int amount = 5;
        int[] coins = { 1, 2, 5 };
        System.out.println(new Solution().change(amount, coins));
    }
}