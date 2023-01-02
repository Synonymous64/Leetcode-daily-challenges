import java.util.*;
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        if(root == null) return new ArrayList<>(){};
        Queue<Node> q = new LinkedList<>();
        List<List<Integer>> res = new ArrayList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> temp = new ArrayList<>();
            while(size-- > 0){
                Node curr = q.poll();
                for(int i = 0; i < curr.children.size(); ++i) q.add(curr.children.get(i));
                temp.add(curr.val);
            }
            res.add(temp);
        }
        return res;
    }
}
public class NaryTreeLevelOrderTraversal{
    public static void main(String[] args) {
        
    }
}
