import java.util.*;
class Solution {
    public int shortestPath(int[][] grid, int k) {
        int[] dirs = {0, 1, 0, -1, 0};
        int rows = grid.length, cols = grid[0].length;
        if(k >= rows + cols - 2) return rows + cols - 2;
        boolean [][][] visited = new boolean[rows][cols][k + 1];
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] {0, 0, k, 0});
        visited[0][0][k] = true;
        while(!q.isEmpty()){
            int[] top = q.poll();
            int r = top[0], c = top[1], currK = top[2], dist = top[3];
            if(r == rows - 1 && c == cols - 1) return dist;
            for(int i = 0; i < 4; ++i){
                int nr = r + dirs[i], nc = c + dirs[i + 1];
                if(nr < 0 || nr == rows || nc < 0 || nc == cols) continue;
                int newK = currK - grid[nr][nc];
                while(newK >= 0 && !visited[nr][nc][newK]){
                    visited[nr][nc][newK] = true;
                    q.add(new int[]{nr, nc, newK, dist + 1});
                }
            }
        }
        return -1;
    }
}
public class ShortestPathinaGridwithObstaclesElimination{
    public static void main(String[] args) {
        int[][] grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
        int k = 1;
        Solution s = new Solution();
        System.out.println(s.shortestPath(grid, k));
    }
}