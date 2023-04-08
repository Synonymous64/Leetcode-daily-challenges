import java.util.*;
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

class Solution {
    public Node cloneGraph(Node node) {
        HashMap<Node, Node> mp = new HashMap<>();
        if(node == null) return null;
        Node first = new Node(node.val, new ArrayList<>());
        mp.put(node, first);
        Queue<Node> q = new LinkedList<>();
        q.offer(node);
        while(!q.isEmpty()){
            Node curr = q.poll();
            for(Node adj: curr.neighbors){
                if(!mp.containsKey(adj)){
                    mp.put(adj, new Node(adj.val, new ArrayList<>()));
                    q.add(adj);
                }
                mp.get(curr).neighbors.add(mp.get(adj));
            }
        }
        return mp.get(node);
    }
}
public class CloneGraph{
    public static void main(String[] args) {
        
    }
}