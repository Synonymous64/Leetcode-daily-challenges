import java.util.*;

class Solution {
    private int mod = 1000000007;
    private int[][] dp = new int[101][201];

    private int helper(int[] locations, int idx, int finish, int fuel) {
        if (fuel <= 0)
            return idx == finish ? 1 : 0;
        if (dp[idx][fuel] != -1)
            return dp[idx][fuel];

        int res = 0;
        if (idx == finish)
            res = 1;

        for (int i = 0; i < locations.length; ++i) {
            if (i != idx && Math.abs(locations[idx] - locations[i]) <= fuel) {
                res = (res % mod + helper(locations, i, finish, fuel - Math.abs(locations[idx] - locations[i])) % mod)
                        % mod;
            }
        }
        return dp[idx][fuel] = res;
    }

    public int countRoutes(int[] locations, int start, int finish, int fuel) {
        for (int[] arr : dp)
            Arrays.fill(arr, -1);
        return helper(locations, start, finish, fuel);
    }
}

public class CountAllPossibleRoutes {
    public static void main(String[] args) {
        int[] locations = { 2, 3, 6, 8, 4 };
        int start = 1, finish = 3, fuel = 5;
        System.out.println(new Solution().countRoutes(locations, start, finish, fuel));
    }
}