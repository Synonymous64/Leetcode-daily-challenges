import java.util.*;
class Solution {
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        Queue<Integer> radiant = new LinkedList<>(), dire = new LinkedList<>();
        for(int i = 0; i < n; ++i){
            if(senate.charAt(i) == 'R') radiant.add(i);
            else dire.add(i);
        }
        if(radiant.isEmpty()) return "Dire";
        else if(dire.isEmpty()) return "Radiant";
        while(!radiant.isEmpty() && !dire.isEmpty()){
            if(radiant.peek() < dire.peek()){
                dire.remove();
                int rad = radiant.poll();
                radiant.add(n + rad);
            } else{
                radiant.remove();
                int dir = dire.poll();
                dire.add(n + dir);
            }
        }
        return radiant.isEmpty() ? "Dire": "Radiant";
    }
}
public class Dota2Senate{
    public static void main(String[] args) {
        String senate = "RD";
        System.out.println(new Solution().predictPartyVictory(senate));
    }
}