import java.util.*;

class Solution {
    private void DFS(ArrayList<Integer>[] adj, boolean[] visited, int node){
        visited[node] = true;
        for(int x: adj[node]){
            if(!visited[x]){
                DFS(adj, visited, x);
            }
        }
        return;
    }
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1)
            return -1;
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            adj[i] = new ArrayList<>();
        }

        for (int[] x : connections) {
            adj[x[0]].add(x[1]);
            adj[x[1]].add(x[0]);
        }
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                DFS(adj, visited, i);
                count++;
            }
        }
        return count - 1;
    }
}

public class NumberofOperationstoMakeNetworkConnected {
    public static void main(String[] args) {
        int n = 4; int[][]connections = {{0,1},{0,2},{1,2}};
        Solution s = new Solution();
        System.out.println(s.makeConnected(n, connections));
    }
}