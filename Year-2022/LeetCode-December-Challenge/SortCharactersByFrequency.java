import java.util.*;
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();        
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }      
        
        PriorityQueue <Character> pq = new PriorityQueue<>((a,b) -> map.get(b) - map.get(a));
        for (char c : map.keySet()) {
            pq.offer(c);
        }
        
        StringBuilder sb = new StringBuilder();       
        while (!pq.isEmpty()) {
            char c = pq.poll();
            for (int i = 0; i < map.get(c); i++) {
                sb.append(c);
            }
        }       
        return sb.toString();
    }   
}
public class SortCharactersByFrequency {
    public static void main(String[] args) {
        String s = "cccaaa";
        Solution S = new Solution();
        System.out.println(S.frequencySort(s));
    }
}
