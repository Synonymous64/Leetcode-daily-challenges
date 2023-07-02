class Solution {
    private int helper(int start, int[][] requests, int[] indegree, int n, int count) {
        if (start == requests.length) {
            for (int i = 0; i < n; i++) {
                if (indegree[i] != 0) {
                    return 0;
                }
            }
            return count;
        }

        // Take
        indegree[requests[start][0]]--;
        indegree[requests[start][1]]++;
        int take = helper(start + 1, requests, indegree, n, count + 1);

        // Not-take
        indegree[requests[start][0]]++;
        indegree[requests[start][1]]--;
        int notTake = helper(start + 1, requests, indegree, n, count);

        return Math.max(take, notTake);
    }
    public int maximumRequests(int n, int[][] requests) {
        int[] indegree = new int[n];
        return helper(0, requests, indegree, n, 0);
    }
}
public class MaximumNumberofAchievableTransferRequests{
    public static void main(String[] args) {
        int n = 5; int[][] requests = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
        Solution s = new Solution();
        System.out.println(s.maximumRequests(n, requests));
    }
}
