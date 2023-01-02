import java.util.*;
class Solution {
    public int size;
    List<Integer> temp = new ArrayList<>();
    List<List<Integer>> res = new ArrayList<>();
    public void DFS(int[][] graph, int currNode){
        temp.add(currNode);
        if(currNode == size) res.add(new ArrayList<>(temp));
        for(int child: graph[currNode]){
            DFS(graph, child);
        }
        temp.remove(temp.size() - 1);
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        size = graph.length - 1;
        DFS(graph, 0);
        return res;
    }
}
public class AllPathsFromSourcetoTarget {
    public static void main(String[] args) {
        
    }
}
