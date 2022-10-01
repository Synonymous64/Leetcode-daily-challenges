class Solution {
    private int[] dp;
    public int numDecodings(String s) {
        dp = new int[s.length() + 1];
        int n = s.length();
        if(n == 0 || s.charAt(0) == '0') return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            if(s.charAt(i - 1) >= '1' && s.charAt(i - 1) <= '9') dp[i] = dp[i - 1];
            if(s.charAt(i - 2) == '1') dp[i] += dp[i - 2];
            else if(s.charAt(i - 2) == '2' && s.charAt(i - 1) >= '0' && s.charAt(i - 1) <= '6') dp[i] += dp[i - 2];
        }
        return dp[n];
    }
}
public class DecodeWays{
    public static void main(String[] args) {
        String s = "10";
        Solution S = new Solution();
        System.out.println(S.numDecodings(s));
    }
}