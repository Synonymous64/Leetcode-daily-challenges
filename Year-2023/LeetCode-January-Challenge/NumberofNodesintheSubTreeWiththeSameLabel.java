import java.util.*;
class Solution {
    private int[] res;
    private ArrayList<Integer>[] graph;
    private int[] DFS(int start, int parent, String labels){
        int[] ans = new int[26];
        Arrays.fill(ans, 0);
        ans[labels.charAt(start) - 'a']++;
        for(int x: graph[start]){
            if(x == parent) continue;
            int[] hsh = DFS(x, start, labels);
            for(int i = 0; i < 26; ++i)
                ans[i] += hsh[i];
        }
        res[start] = ans[labels.charAt(start) - 'a'];
        return ans;
    }
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        res = new int[n];
        Arrays.fill(res, 0);
        graph = new ArrayList[n];
        for(int i = 0; i < n; ++i) graph[i] = new ArrayList<>();
        for(int[] x: edges){
            graph[x[0]].add(x[1]);
            graph[x[1]].add(x[0]);
        }
        DFS(0, -1, labels);
        return res;
    }
}
public class NumberofNodesintheSubTreeWiththeSameLabel {
    public static void main(String[] args) {
        int n = 7;
        int[][] edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        String labels = "abaedcd";
        Solution s = new Solution();
        int[] res = s.countSubTrees(n, edges, labels);
        for(int x: res) System.out.print(x + " ");
    }
}
