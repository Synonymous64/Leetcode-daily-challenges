import java.util.*;
class Solution {
    public boolean possibleBipartition(int n, int[][] dislikes) {
        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        for(int i = 0; i <= n; ++i)
            adj[i] = new ArrayList<>();
        int[] color = new int[n + 1];
        boolean[] visited = new boolean[n + 1];
        for(int i = 0; i < dislikes.length; ++i){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].add(v);
            adj[v].add(u);
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i <= n; ++i){
            if(!visited[i]){
                color[i] = 1;
                q.add(i);
                while(!q.isEmpty()){
                    int curr = q.poll();
                    if(visited[curr]) continue;
                    visited[curr] = true;
                    for(int x: adj[curr]){
                        if(color[x] == color[curr]) return false;
                        else if(color[curr] == 1) color[x] = 2;
                        else color[x] = 1;
                        q.add(x);
                    }
                }
            }
        }
        return true;
    }
}
public class PossibleBipartition {
    public static void main(String[] args) {
        int n = 4;
        int[][] dislikes = {{1,2},{1,3},{2,4}};
        Solution s = new Solution();
        System.out.println(s.possibleBipartition(n, dislikes));
    }
}
