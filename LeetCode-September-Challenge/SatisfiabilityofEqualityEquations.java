import java.util.*;
class Solution {
    private int[] parent;
    private int find(int node){
        if(parent[node] == -1) return node;
        return parent[node] = find(parent[node]);
    }
    private void setUnion(int a, int b){
        int x = find(a), y = find(b);
        if(x != y) parent[x] = y;
    }
    public boolean equationsPossible(String[] equations) {
        parent = new int[26];
        Arrays.fill(parent, -1);
        for(String eq : equations){
            if(eq.charAt(1) == '=') {
                int a = eq.charAt(0) - 'a';
                int b = eq.charAt(3) - 'a';
                setUnion(a, b);
            }
        }
        for(String eq : equations){
            int a = eq.charAt(0) - 'a';
            int b = eq.charAt(3) - 'a';
            if(eq.charAt(1) == '!' && find(a) == find(b)) return false;
        }
        return true;
    }
}
public class SatisfiabilityofEqualityEquations {
    public static void main(String[] args) {
        String[]  equations = {"a==b","b==a"};
        Solution s = new Solution();
        System.out.println(s.equationsPossible(equations));
    }
}
