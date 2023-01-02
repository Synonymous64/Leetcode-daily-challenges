import java.util.*;
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[rooms.size()];
        q.add(0); visited[0] = true;
        while(!q.isEmpty()){
            int curr = q.poll();
            for(int x: rooms.get(curr)){
                if(!visited[x]){
                    visited[x] = true;
                    q.add(x);
                }
            }
        }
        for(boolean x: visited) if(!x) return false;
        return true;
    }
}
public class KeysandRooms {
    public static void main(String[] args) {
    }
}
