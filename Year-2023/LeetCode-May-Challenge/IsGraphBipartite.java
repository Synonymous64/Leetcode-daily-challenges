import java.util.*;
class Solution {
    private boolean DFS(int[][] graph, int[] color, int idx){
        for(int x: graph[idx]){
            if(color[x] == -1){
                color[x] = 1 - color[idx];
                if(!DFS(graph, color, x)) return false;
            }
            else if(color[x] == color[idx]) return false;
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        Arrays.fill(color, -1);
        for(int i = 0; i < n; ++i){
            if(color[i] == -1){
                color[i] = 1;
                if(!DFS(graph, color, i)) return false;
            }
        }
        return true;
    }
}
public class IsGraphBipartite{
    public static void main(String[] args) {
        int[][] graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
        System.out.println(new Solution().isBipartite(graph));
    }
}