import java.util.*;

class Solution {
    private boolean DFS(ArrayList<Integer> adj[], boolean visited[], int idx, boolean visitedF[]) {
        if (visitedF[idx])
            return false;
        if (visited[idx])
            return true;

        visited[idx] = visitedF[idx] = true;

        for (int node : adj[idx])
            if (!DFS(adj, visited, node, visitedF))
                return false;

        visitedF[idx] = false;

        return true;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<Integer> adj[] = new ArrayList[numCourses];

        for(int i = 0; i < adj.length; ++i)
            adj[i] = new ArrayList<>();

        for (int i = 0; i < prerequisites.length; ++i)
            adj[prerequisites[i][0]].add(prerequisites[i][1]);

        boolean[] visited = new boolean[numCourses], visitedF = new boolean[numCourses];
        Arrays.fill(visited, false);
        Arrays.fill(visitedF, false);

        for (int i = 0; i < numCourses; ++i)
            if (!visited[i] && !DFS(adj, visited, i, visitedF))
                return false;

        return true;

    }
}

public class CourseSchedule {
    public static void main(String[] args) {
        int numCourses = 2;
        int[][] prerequisites = { { 1, 0 } };
        System.out.println(new Solution().canFinish(numCourses, prerequisites));
    }
}