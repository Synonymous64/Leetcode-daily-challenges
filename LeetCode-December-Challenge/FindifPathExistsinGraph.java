import java.util.*;
class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        ArrayList<Integer> [] adj = new ArrayList[n];
        for(int i = 0; i < n; i++){
            adj[i] = new ArrayList<>();
        }    
        for(int i = 0; i < edges.length; ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].add(v);
            adj[v].add(u);
        }
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n];
        q.add(source);
        visited[source] = true;
        while(!q.isEmpty()){
            int curr = q.poll();
            if(curr == destination) return true;
            for(int x: adj[curr]){
                if(!visited[x]){
                    visited[x] = true;
                    q.add(x);
                }
            }
        }
        return false;
    }
}
public class FindifPathExistsinGraph{
    public static void main(String[] args) {
        
    }
}