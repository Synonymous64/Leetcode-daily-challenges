import java.util.*;

class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length, size = Math.max(n + 1, m + 1);
        if(n == 1 && m == 1 && nums1[0] != nums2[0]) return 0;
        int[][] dp = new int[size][size];
        for (int[] arr : dp)
            Arrays.fill(arr, -1);
        for (int i = 0; i < Math.max(n, m); ++i) {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
}

public class UncrossedLines {
    public static void main(String[] args) {
        int[] nums1 = { 1, 4, 2 }, nums2 = { 1, 2, 4 };
        System.out.println(new Solution().maxUncrossedLines(nums1, nums2));
    }
}