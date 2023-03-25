import java.util.*;

class Solution {
    private int DFS(ArrayList<Integer>[] adj, boolean[] visited, int node) {
        visited[node] = true;
        int res = 1;
        for (int x : adj[node]) {
            if (!visited[x]) {
                res += DFS(adj, visited, x);
            }
        }
        return res;
    }

    public long countPairs(int n, int[][] edges) {
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();
        boolean[] visited = new boolean[n];
        for (int[] x : edges) {
            adj[x[0]].add(x[1]);
            adj[x[1]].add(x[0]);
        }
        ArrayList<Integer> unreachedNode = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int x = DFS(adj, visited, i);
                unreachedNode.add(x);
            }
        }
        long temp = 0;
        long res = 0;
        for (int i = 0; i < unreachedNode.size(); ++i) {
            temp += unreachedNode.get(i);
            res += (n - temp) * unreachedNode.get(i);
        }
        return res;
    }
}

public class CountUnreachablePairsofNodesinanUndirectedGraph {
    public static void main(String[] args) {
        int n = 7;
        int[][] edges = { { 0, 2 }, { 0, 5 }, { 2, 4 }, { 1, 6 }, { 5, 4 } };
        System.out.println(new Solution().countPairs(n, edges));
    }
}