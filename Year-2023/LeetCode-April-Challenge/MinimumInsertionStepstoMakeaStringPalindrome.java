class Solution {
    private String reverse(String s) {
        char[] str = s.toCharArray();
        int low = 0, high = s.length() - 1;
        while (low < high) {
            char temp = str[low];
            str[low] = str[high];
            str[high] = temp;
            low++;
            high--;
        }
        return new String(str);
    }

    public int minInsertions(String s) {
        int n = s.length();
        String rev = s;
        rev = reverse(rev);
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (s.charAt(i - 1) == rev.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n - dp[n][n];

    }
}

public class MinimumInsertionStepstoMakeaStringPalindrome {
    public static void main(String[] args) {
        String s = "mbadm";
        System.out.println(new Solution().minInsertions(s));
    }
}