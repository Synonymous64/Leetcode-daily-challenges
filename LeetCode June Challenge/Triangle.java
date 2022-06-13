import java.util.*;
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n];
        Arrays.fill(dp, 0);
        for(int i = 0; i < n; ++i){
            dp[i] = triangle.get(n - 1).get(i);
        }
        for(int i = n - 2; i >= 0; --i){
            for(int j = 0; j < triangle.get(i).size(); ++j){
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
}
public class Triangle {
    public static void main(String[] args) {
        List<List<Integer>> triangle = new ArrayList<>();
        Solution s = new Solution();
        System.out.println(s.minimumTotal(triangle));
    }
}
